import subprocess
import re
import sys
num_iterations = 1000
files_to_execute = ['cpu_ops/4_ker_thread.c -lpthread']#, 'cpu_ops/4_process.c']
#files_to_execute = ['cpu_ops/2_measure_arg.c -lpthread']
#files_to_execute = ['cpu_ops/1_measure_loop.c -lpthread']
#files_to_execute = ['cpu_ops/5_context_ker_thread.c -lpthread', 'cpu_ops/5_context_process.c']
#files_to_execute = ['mem_ops/2_ram_band.c', 'mem_ops/3_page_fault.c']
for f in files_to_execute:
    subprocess.check_output('gcc '+ f + ' -O0', shell=True)
    c_op_file = open("Outputs/"+ f.split(" ")[0].split("/")[1]+".cyc"+".csv", 'w')
#    s_op_file = open("Outputs/"+ f.split(" ")[0].split("/")[1]+".sec"+".csv", 'w')
    for i in range(num_iterations):
        op = subprocess.check_output(['taskset', '--cpu-list', '1', 'nice', '-n', '-20', './a.out'])
        op = op.decode("utf-8")
        c_values = re.findall(r'\D*(\d*)\D*cycles', op, flags=re.M)
        c_op_file.write(','.join(c_values) + '\n')
       # s_values = re.findall(r'.*\s*(\d+\.\d+)\s+seconds', op, flags=re.M)
       # s_op_file.write(','.join(s_values) + '\n')

