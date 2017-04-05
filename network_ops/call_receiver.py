import sys
import subprocess
i = 0
while i < 100:
    subprocess.call(["./receiver", sys.argv[1]])
    i += 1
