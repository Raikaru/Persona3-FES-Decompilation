import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class CreateRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) throw new IllegalArgumentException("usage: CreateRange <map> <end> <output>");
        Address base = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0);
        String[] lines = java.nio.file.Files.readAllLines(java.nio.file.Paths.get(args[0])).toArray(new String[0]);
        List<Address> addrs = new ArrayList<>();
        for (String line : lines) {
            String t = line.trim();
            if (!t.matches("[0-9A-Fa-f]{8}.*")) continue;
            long off = Long.parseUnsignedLong(t.substring(0, 8), 16);
            if (off >= 0x1f9170 && off <= 0x201a50) addrs.add(base.add(off));
        }
        addrs.sort(Comparator.naturalOrder());
        long end = Long.parseUnsignedLong(args[1], 16);
        FunctionManager fm = currentProgram.getFunctionManager();
        for (int i = 0; i < addrs.size(); i++) {
            Address a = addrs.get(i);
            Address b = (i + 1 < addrs.size()) ? addrs.get(i + 1).subtract(1) : base.add(end);
            Function f = fm.getFunctionAt(a);
            if (f == null) {
                try { fm.createFunction(null, a, new AddressSet(a, b), SourceType.USER_DEFINED); }
                catch (Exception ex) { println("create failed " + a + ": " + ex); }
            }
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(args[2]))) {
            writer.write("/* Generated Ghidra reference; do not compile. */\n\n");
            for (Address a : addrs) {
                Function f = fm.getFunctionAt(a);
                writer.write(String.format("/* FUN_%08X %s */\n", a.getOffset(), f == null ? "?" : f.getName()));
                if (f != null) {
                    DecompileResults r = decompiler.decompileFunction(f, 120, monitor);
                    if (r.decompileCompleted()) writer.write(r.getDecompiledFunction().getC());
                    else writer.write("/* DECOMPILE_FAILED: " + r.getErrorMessage() + " */");
                }
                writer.write("\n\n");
            }
        }
        decompiler.dispose();
    }
}
