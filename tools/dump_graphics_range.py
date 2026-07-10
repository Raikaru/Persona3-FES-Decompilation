#@category Persona3
# Dumps decompiler output and instruction-level function metadata for a bounded range.

from ghidra.app.decompiler import DecompInterface
from java.io import FileWriter, BufferedWriter

START = 0x00340100
END = 0x00357CE0
args = getScriptArgs()
if len(args) != 1:
    raise ValueError("usage: dump_graphics_range.py <output-path>")
OUT = args[0]

interface = DecompInterface()
interface.openProgram(currentProgram)
functions = []
manager = currentProgram.getFunctionManager()
for function in manager.getFunctions(True):
    entry = function.getEntryPoint().getOffset()
    if START <= entry <= END:
        functions.append(function)
functions.sort(key=lambda function: function.getEntryPoint().getOffset())

writer = BufferedWriter(FileWriter(OUT))
writer.write("/* Generated Ghidra reference; do not compile. */\n\n")
for function in functions:
    entry = function.getEntryPoint().getOffset()
    writer.write("/* FUN_%08X %s */\n" % (entry, function.getName()))
    result = interface.decompileFunction(function, 60, monitor)
    if result.decompileCompleted():
        writer.write(result.getDecompiledFunction().getC())
    else:
        writer.write("/* DECOMPILE_FAILED: %s */" % result.getErrorMessage())
    writer.write("\n\n")
writer.close()
print("Dumped %d functions to %s" % (len(functions), OUT))
