#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    volatile long long unsigned int a, b;
    volatile long long unsigned int from_disk, from_memory;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    struct stat buf;
    int fd = open("output.dat", 'r');
    int stat = fstat(fd, &buf);
    char *dat = (char *)mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    char *buffer=(char *) malloc(buf.st_size);
    char *bufferDest=(char *) malloc(buf.st_size);
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    memcpy(buffer, dat, buf.st_size);
    __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
    __asm__ __volatile__ ("cpuid");
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
    from_disk = b-a;
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    memcpy(buffer, dat, buf.st_size);
    __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
    __asm__ __volatile__ ("cpuid");
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
    from_memory = b-a;
    printf("%llu cycles\n", from_disk-from_memory);
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    memcpy(buffer, dat, buf.st_size);
    __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
    __asm__ __volatile__ ("cpuid");
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
}
