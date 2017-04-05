#include <stdio.h>
int main(int argc, char* argv[])
{
  volatile unsigned long long a, b, dummy;
  volatile unsigned hi,lo;
  int i = 0;
  volatile long double cpu_speed = 2592124150;
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  for(i=0; i<1; i++){
 
  }
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for reading time: %llu cycles\n", b-a);
  printf("Overhead for reading time: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  for(i=0; i<10; i++){
 
  }
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for reading time: %llu cycles\n", (long long unsigned int)(b-a)/10);
  printf("Overhead for reading time: %.12Lf seconds\n", (long double)(b-a)/10*cpu_speed);
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  for(i=0; i<100; i++){
 
  }
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for reading time: %llu cycles\n",(long long unsigned int)(b-a)/100);
  printf("Overhead for reading time: %.12Lf seconds\n", (long double)(b-a)/100*cpu_speed);
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  for(i=0; i<1000; i++){
 
  }
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for reading time: %llu cycles\n",(long long unsigned int)(b-a)/1000);
  printf("Overhead for reading time: %.12Lf seconds\n", (long double)(b-a)/1000*cpu_speed);
}
