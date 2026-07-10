// @category Persona3

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class DumpRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) {
            throw new IllegalArgumentException("usage: DumpRange <start-hex> <end-hex> <output-path>");
        }

        long start = Long.parseUnsignedLong(args[0].replaceFirst("^(0x|0X)", ""), 16);
        long end = Long.parseUnsignedLong(args[1].replaceFirst("^(0x|0X)", ""), 16);
        String outputPath = args[2];

        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);

        List<Function> functions = new ArrayList<>();
        FunctionIterator iterator = currentProgram.getFunctionManager().getFunctions(true);
        while (iterator.hasNext()) {
            Function function = iterator.next();
            long entry = function.getEntryPoint().getOffset();
            if (entry >= start && entry <= end) {
                functions.add(function);
            }
        }
        functions.sort(Comparator.comparingLong(function -> function.getEntryPoint().getOffset()));

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputPath))) {
            writer.write("/* Generated Ghidra reference; do not compile. */\n\n");
            for (Function function : functions) {
                if (monitor.isCancelled()) {
                    break;
                }
                long entry = function.getEntryPoint().getOffset();
                writer.write(String.format("/* FUN_%08X %s */\n", entry, function.getName()));
                DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                if (result.decompileCompleted()) {
                    writer.write(result.getDecompiledFunction().getC());
                } else {
                    writer.write("/* DECOMPILE_FAILED: " + result.getErrorMessage() + " */");
                }
                writer.write("\n\n");
            }
        } finally {
            decompiler.dispose();
        }

        println("Dumped " + functions.size() + " functions to " + outputPath);
    }
}
