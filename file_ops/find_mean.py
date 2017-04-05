import sys
filename = sys.argv[1]
f = open(filename, "r")
lines = f.readlines()
#lines = map(lambda line: line.split(",")[1] if len(line.split(",")) > 1 else line.split(",")[0], f.readlines())
lines = list(map(lambda line: int(line.strip()), lines))
lines = sorted(lines)
print(sum(lines)/len(lines))
