#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int x=1;
void func0()
{
  x+=1;
}
int main(int argc, char* argv[])
{
  volatile unsigned long long a, b, dummy;
  volatile unsigned hi,lo;
  int i = 0;
  volatile long double cpu_speed = 2592124150;
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  
  getpid();

  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for making system call: %llu cycles\n", b-a);
  printf("Overhead for making system call: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  
  func0();

  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for making procedure call: %llu cycles\n", b-a);
  printf("Overhead for making procedure call: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);
}
