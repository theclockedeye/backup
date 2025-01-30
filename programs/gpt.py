import subprocess
import sys

# Check if the user provided the C file name as an argument
if len(sys.argv) < 2:
    print("Usage: python compile_and_run.py <filename_without_extension>")
    sys.exit(1)

# Construct the gcc command
cmd = 'gcc ' + sys.argv[1]

# Run the gcc command
result = subprocess.run(cmd, shell=True, capture_output=True, text=True)

# Check if the command was successful (returncode 0)
if not result.returncode:
    # If successful, run the generated executable
    subprocess.run("a", shell=True)
else:
    # If there are errors, print them
    print("Error during compilation...")
    for line in result.stderr.splitlines():
        print(line)
