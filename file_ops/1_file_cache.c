#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv)
{
    volatile long long unsigned int a, b;
    long long unsigned int total_cycles=0;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    char str[100];
    strcpy(str, "dummy_files/");
    strcat(str, argv[1]);
    strcat(str, ".dummy");
    int fp = open(str, O_RDONLY);
    char val[10000];
    int i = 0;
    while(read(fp, &val, 1000))
    {
        ;
    }
    while(i < 5)
    {
        lseek(fp, 0, SEEK_SET);
        __asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
        while(read(fp, &val, 1000))
        {
            ;
        }
        __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
        __asm__ __volatile__ ("cpuid");
        b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
        total_cycles += b-a;
        i++;
    }
    printf("%d, %llu\n", atoi(argv[1]), (long long unsigned int)total_cycles/5);
    //read(fp, val, 
}
