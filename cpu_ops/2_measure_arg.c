#include <stdio.h>
int x=1;
void func0()
{
  x+=1;
}
void func1(int a)
{
  x+=1;
}
void func2(int a, int b)
{
  
  x+=1;
}
void func3(int a, int b, int c)
{
  x+=1;
}
void func4(int a, int b, int c, int d)
{
  x+=1;
}
void func5(int a, int b, int c, int d, int e)
{
  x+=1;
}
void func6(int a, int b, int c, int d, int e, int f)
{
  x+=1;
}
void func7(int a, int b, int c, int d, int e, int f, int g)
{
  x+=1;
}
int main(int argc, char* argv[])
{
  volatile unsigned long long a,b;
  volatile unsigned hi, lo;
  int i = 0;
  func0();
  func1(5);
  func1(5);
  func1(5);

  
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func0();
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 0 arguments: %llu cycles\n", b-a);

  func0();

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func1(5);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 1 argument: %llu cycles\n", b-a);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func2(5, 10);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 2 arguments: %llu cycles\n", b-a);
 
  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func3(5, 10, 15);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 3 arguments: %llu cycles\n", b-a);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func4(5, 10, 15, 20);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 4 arguments: %llu cycles\n", b-a);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func5(5, 10, 15, 20, 25);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 5 arguments: %llu cycles\n", b-a);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func6(5, 10, 15, 20, 25, 30);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 6 arguments: %llu cycles\n", b-a);

  __asm__ __volatile__ ("cpuid");
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  func7(5, 10, 15, 20, 25, 30, 35);
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  __asm__ __volatile__ ("cpuid");
  b = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
  printf("Number of cycles 7 arguments: %llu cycles\n", b-a);
  return 0;
}

