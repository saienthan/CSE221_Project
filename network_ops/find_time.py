files = ['128', '256', '512', '1024', '2048', '4096', '8192', '16384', '32768', '65536']
for f in files:
    fp = open('out'+f, 'r')
    lines = fp.read().split()
    nums = map(lambda x: int(x.split(".")[0]), lines)
    cycles = sum(nums)/len(nums)
    clock = 2.6 * 10 **9
    print(cycles/clock)
