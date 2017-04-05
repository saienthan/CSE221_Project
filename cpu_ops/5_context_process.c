#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  volatile unsigned long long a, b;
  volatile unsigned hi,lo;
  int fd[2];
  int fd1[2];
  pipe(fd);
  pipe(fd1);
  int i = 0;
  int status;
  char string[] = "0";
  char read_buffer[80];
  char read_buffer1[80];
  volatile long double cpu_speed = 2592124150;
    __asm__ __volatile__ ("cpuid");
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    write(fd[1], string, (strlen(string)+1));
    read(fd[0], read_buffer1, sizeof(read_buffer1));
    __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
    __asm__ __volatile__ ("cpuid");
    b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    unsigned long long single = b-a;
    printf("%llu cycles\n", single);
  pid_t pid;
  
  pid = fork();
  if(pid == 0)
  {
      __asm__ __volatile__ ("cpuid");
      __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
      a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
      write(fd[1], string, (strlen(string)+1));
      read(fd1[0], read_buffer1, sizeof(read_buffer1));
      __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
      __asm__ __volatile__ ("cpuid");
      b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
      printf("Overhead for context switch: %llu cycles\n", ((b-a)/2)-single);
      printf("Overhead for context switch: %.12Lf seconds\n", ((long double)((((b-a)/2) - single)/(cpu_speed))));
  }
  else
  {
      read(fd[0], read_buffer, sizeof(read_buffer));
      write(fd1[1], string, (strlen(string)+1));
  }
}
