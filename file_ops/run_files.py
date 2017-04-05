import subprocess
#file_sizes = [512, 1024, 2048, 4096, 8192, 16384]# 32768, 65536, 131072, 262144, 524288]
file_sizes = [512, 1024, 2048]# 4096, 8192, 16384]
#file_sizes = [1024000]
#file_sizes = [512000]
#files = ['1_file_cache.c']
#files = ['2_read_time.c', '2_read_time_random.c']
files = ['3_read_time.c', '3_read_time_random.c']
for f in files:
    #subprocess.call(['gcc', '2_read_time_random.c', '-lm', '-O0'])
    subprocess.call(['gcc', f, '-O0', '-lm'])
    for fs in file_sizes:
        vals = []
#        subprocess.call(['fallocate', '-l', str(fs)+'K', 'dummy_files/'+str(fs)+'.dummy'])
        for i in range(10):
            op = subprocess.check_output(['./a.out', str(fs)])
            vals.append(int(op.decode("utf-8")))
            #vals.append(op.decode("utf-8"))
#        subprocess.call(['rm', 'dummy_files/'+str(fs)+'.dummy'])
        #print(' '.join(vals), end="")
        print(fs, ",", sum(vals)/len(vals))
