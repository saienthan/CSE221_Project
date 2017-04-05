#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
char read_buffer[80];
char read_buffer1[80];
int fd[2];
int fd1[2];
char *string = "0";
void *dummyfunction(void * sObj)
{
    write(fd1[1], string, (strlen(string)+1));
    read(fd[0], read_buffer1, sizeof(read_buffer1));
}
int main(int argc, char *argv[])
{
    volatile unsigned long long a, b;
    volatile unsigned long long single;
    volatile unsigned hi,lo;
    int i = 0;
    volatile long double cpu_speed = 2592124150;
    pipe(fd);
    pipe(fd1);
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    write(fd[1], string, (strlen(string)+1));
    read(fd[0], read_buffer1, sizeof(read_buffer1));
    __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
    __asm__ __volatile__ ("cpuid");
    b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    single = b-a;
    printf("%llu cycles\n", single);

    int ret_code;
    pthread_t thread_id;
    ret_code = pthread_create(&thread_id,NULL, dummyfunction, NULL);
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    read(fd1[0], read_buffer1, sizeof(read_buffer1));
    write(fd[1], string, (strlen(string)+1));
    __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
    __asm__ __volatile__ ("cpuid");
    b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    printf("Overhead for context switch: %llu cycles\n", ((b-a)/2)-single);
    printf("Overhead for context switch: %.12Lf seconds\n", ((long double)((((b-a)/2)-single)/(cpu_speed))));
    }
