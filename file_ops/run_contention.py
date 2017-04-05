import subprocess
import time
num_files = 20
subprocess.call(['gcc', '4_contention.c', '-O0'])
for fnum in range(num_files):
    subprocess.call(['fallocate', '-l', '500M', 'dummy_files/'+str(fnum)])
    for i in range(1, 20):
        subprocess.call(['rm','nohup.out'])
        op = subprocess.check_output(["bash", "run_contention.sh", str(i)])
        vals = list(map(int, op.decode("utf-8").split()))
        print(sum(vals)/len(vals))
        time.sleep(3)

