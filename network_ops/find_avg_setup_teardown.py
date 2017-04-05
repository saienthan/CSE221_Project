"""
import subprocess
for i in range(100):
    op = subprocess.check_output(["./conn_receiver", "100"])
    print(op.decode("utf-8"), end="")
"""
f = open("setup_teardown", "r")
lines = f.readlines()
setup = [int(lines[x]) for x in range(0, len(lines), 2)]
teardown = [int(lines[x]) for x in range(1, len(lines), 2)]
print(sum(setup)/len(setup))
print(sum(teardown)/len(teardown))
