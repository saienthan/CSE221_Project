import sys
import numpy as np
filename = sys.argv[1]
f = open(filename, "r")
lines = list(map(lambda line: list(map(int, line.split(","))) if len(line.split(",")) > 1 else line.split(",")[0], f.readlines()))
np_lines = np.array(lines)
print(np_lines.shape)
print(np.mean(np_lines, axis=0))
print(np.std(np_lines, axis=0))
#lines = map(int, lines)
#lines = sorted(lines)
#print(sum(lines[100:-1000])/8900)

