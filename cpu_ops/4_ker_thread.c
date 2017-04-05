#pragma OPTIMIZE OFF

#include <pthread.h>
#include <stdio.h>
volatile unsigned hi1,lo1;
volatile unsigned hi,lo;
volatile unsigned long long a1, b1;
int x = 0;
void* func(){
  __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
  __asm__ __volatile__ ("cpuid");
  b1 = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
}
int main(int argc, char *argv[])
{
  volatile unsigned long long a, b;
  int i = 0;
  volatile long double cpu_speed = 2592124150;
  int ret_code;
  for(; i<20; i++){
  pthread_t thread_id;
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  ret_code = pthread_create(&thread_id,NULL, &func, NULL);
  
  pthread_join(thread_id, NULL);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Overhead for creating kernel thread: %llu cycles\n", b1-a);
  printf("Overhead for creating kernel thread: %.12Lf seconds\n", (long double)(b1-a)/cpu_speed);
  printf("Overhead for end of kernel thread execution: %llu cycles\n", b-a);
  printf("Overhead for end of kernel thread execution: %.12Lf seconds\n", (long double)(b-a)/cpu_speed);
 }

}
