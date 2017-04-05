import sys
import subprocess
filename = "temp"
f = open(filename, "r")
lines = f.readlines()
lines = lines[:-1]
#lines = map(lambda line: line.split(",")[1] if len(line.split(",")) > 1 else line.split(",")[0], f.readlines())
lines = list(map(lambda line: int(line.strip()), lines))
lines = sorted(lines)
print(lines)
print(sum(lines[:-100])/len(lines[:-100]))
