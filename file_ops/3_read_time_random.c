#define _GNU_SOURCE
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<malloc.h>
#include<string.h>
#define BLKSIZE 4096
int main(int argc, char** argv)
{
    system("sync");
    volatile long long unsigned int a, b;
    long long unsigned int total_cycles=0;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    char *subblk = memalign(BLKSIZE, 16384);
    char fname[800];
    strcpy(fname, "/home/osgroup/ssdir/");
    strcat(fname, argv[1]);
    strcat(fname, ".dummy");
    int fp = open(fname, O_DIRECT, 0);
    //int dc_fp = open("/proc/sys/vm/drop_caches", O_WRONLY, 0);
    //char buffer = '3';
    int val = 0;
    //printf("%s\n", fname);
    int r;
    val = 1;
    int i = 0;
    int num_blocks = atoi(argv[1]) * 1024/BLKSIZE;
    while(i < num_blocks)
    {
        system("sync");
        //write(dc_fp, &buffer, (ssize_t)1);
        i++;
        r = rand();
        r = r%(int)(ceil(num_blocks));
        lseek(fp, r*BLKSIZE, SEEK_SET);
        __asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        a = ((unsigned long long)lo)|(((unsigned long long)hi)<<32 );
        val = read(fp, subblk, BLKSIZE);
        __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
        __asm__ __volatile__ ("cpuid");
        b = ((unsigned long long)lo)|(((unsigned long long)hi)<<32 );
        total_cycles += b-a;
    }
    printf("%d\n", (int)(total_cycles*4.096/(atoi(argv[1]))));
}
