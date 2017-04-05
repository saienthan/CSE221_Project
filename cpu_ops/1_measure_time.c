#include <stdio.h>
int main(int argc, char* argv[])
{
  volatile unsigned long long a, b, dummy;
  volatile unsigned hi,lo;
  volatile unsigned long long cpu_speed = 2592124150;
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );

  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  dummy = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for reading time: %llu cycles\n", b-a);
  printf("Overhead for reading time: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);
}
