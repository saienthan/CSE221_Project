#pragma OPTIMIZE OFF
#define _GNU_SOURCE
#include<stdlib.h>
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
    //strcpy(fname, "/home/osgroup/ssdir/dummy_files/");
    strcpy(fname, "dummy_files/");
    strcat(fname, argv[1]);
    strcat(fname, ".dummy");
    //printf("%s\n", fname);
    int fp = open(fname, O_DIRECT, 0);
    //int dc_fp = open("/proc/sys/vm/drop_caches", O_WRONLY, 0);
    //char buffer = '3';
    int val = 1;
    int i = 0;
    val = 1;
    while(val)
    {
        system("sync");
        i++;
        //write(dc_fp, &buffer, (ssize_t)1);
        __asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));

        val = read(fp,subblk,16384);
        __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
        __asm__ __volatile__ ("cpuid");
        a = ((unsigned long long)lo)|(((unsigned long long)hi)<<32 );
        b = ((unsigned long long)lo1)|(((unsigned long long)hi1)<<32 );
//        printf("%d\n", val);
        total_cycles += b-a;
    }
    printf("%d\n", (int)(total_cycles*4.096/(atoi(argv[1]))));
}
