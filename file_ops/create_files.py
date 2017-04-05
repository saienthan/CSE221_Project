import subprocess
file_sizes = list(range(50, 1050, 50))
for fs in file_sizes:
    subprocess.call(['fallocate', '-l', str(fs)+'M', 'dummy_files/'+str(fs)+'.dummy'])
