import sys
import numpy as np
f = open(sys.argv[1], "r")
lines = f.readlines()
lines = list(map(lambda line: line.strip().split(), lines))
print(lines[0])
print(lines[3])
creation = [int(lines[i][4]) for i in range(0, len(lines), 4)]
end = [float(lines[i][6]) for i in range(2, len(lines), 4)]
creation = np.array(creation)
end = np.array(end)
print(np.mean(creation))
print(np.std(creation))
print(np.mean(end))
print(np.std(end))
