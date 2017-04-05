#pragma OPTIMIZE OFF

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>
int main()
{
  int x = 0;
  volatile unsigned long long a, b;
  volatile unsigned long long a1, b1;
  volatile unsigned hi,lo;
  volatile unsigned hi1,lo1;
  volatile unsigned hi2,lo2;
  int i = 0;
  int status;
  pid_t pid;
  volatile long double cpu_speed = 2592124150;
  for(i=0; i<1000; i++)
  {
         asm volatile ("cpuid\n\t"
		          "rdtsc\n\t"
		          "mov %%edx, %0\n\t"
		          "mov %%eax, %1\n\t"
		          : "=r" (hi), "=r" (lo)
		          :: "%rax", "%rbx", "%rcx", "%rdx");

  pid = fork();
	            asm volatile ("rdtscp\n\t"
		          "mov %%edx, %0\n\t"
		          "mov %%eax, %1\n\t"
		          "cpuid\n\t"
		          : "=r" (hi1), "=r" (lo1)
		          :: "%rax", "%rbx", "%rcx", "%rdx");
          wait(&status);
	  __asm__ __volatile__ ("rdtscp" : "=a"(lo2), "=d"(hi2));
	  __asm__ __volatile__ ("cpuid");
      a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
	  b1 = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
	  b = ( (unsigned long long)lo2)|( ((unsigned long long)hi2)<<32 );
  if(pid == 0) {
      _exit(EXIT_FAILURE);
  }
	  printf("Overhead for process creation: %llu cycles\n", (b1-a));
	  printf("Overhead for process creation: %.12Lf seconds\n", (long double)(b1-a)/cpu_speed);
	  printf("Overhead for process creation child termination: %llu cycles\n", (b-a));
	  printf("Overhead for process creation child termination: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);
  }
}
