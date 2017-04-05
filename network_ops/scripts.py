import subprocess
import re
import _thread
subprocess.check_output('gcc sender.c -O0 -o sender', shell=True)
subprocess.check_output('gcc receiver.c -O0 -o receiver', shell=True)
packet_size = '1000'
c_op_file = open("../Outputs/rtt.cyc.csv", 'w')
i = 0

subprocess.Popen(['taskset', '--cpu-list', '1','nice', '-n', '-20', './sender', packet_size])
while i < 100:
    i += 1
    op = subprocess.check_output(['taskset', '--cpu-list', '1','nice', '-n', '-20', './receiver', packet_size])
    op = op.decode("utf-8")
    c_values = re.findall(r'\D*(\d*)\D*cycles', op, flags=re.M)
    c_op_file.write(','.join(c_values) + '\n')
