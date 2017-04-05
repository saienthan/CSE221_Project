#pragma OPTIMIZE OFF
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

size_t getFileSize(int fd) {
    struct stat buf;
    fstat(fd, &buf);
    return buf.st_size;
}

int main(int argc, char* argv[]) {
	int loop=100;
    
     unsigned cycles_low0, cycles_high0, cycles_low1, cycles_high1;
    system("sync");
    system("echo 3 > /proc/sys/vm/drop_caches");

 
	int fd = open(argv[1], O_RDONLY | O_DIRECT);   // use O_DIRECT and pass filename

	size_t size = getFileSize(fd);

	blksize_t block_size = 16 * 1024;

    
	void* buf = memalign(4096, block_size);
	unsigned long long start, end, time = 0;
	int nBlocks = size/block_size;

	int i;
	for (i = 0; i < loop; i++) {
		
     system("sync");
    system("echo 3 > /proc/sys/vm/drop_caches");     //disbale caching

		  asm volatile ("cpuid\n\t"
		          "rdtsc\n\t"
		          "mov %%edx, %0\n\t"
		          "mov %%eax, %1\n\t"
		          : "=r" (cycles_high0), "=r" (cycles_low0)
		          :: "%rax", "%rbx", "%rcx", "%rdx");
				  
		long offset = (rand()%(size / 512)) * 512;
        off_t sk = lseek(fd, offset, SEEK_SET);
		read(fd, buf, block_size);
		
		 asm volatile ("rdtscp\n\t"
		          "mov %%edx, %0\n\t"
		          "mov %%eax, %1\n\t"
		          "cpuid\n\t"
		          : "=r" (cycles_high1), "=r" (cycles_low1)
		          :: "%rax", "%rbx", "%rcx", "%rdx");
				  
    start = ( ((unsigned long int)cycles_high0 << 32) | cycles_low0 );
    end = ( ((unsigned long int)cycles_high1 << 32) | cycles_low1 );
        time+=(end-start);
		
		
	}
   printf("%g\n", (time/loop)/2.6e9);
	close(fd);
	free(buf);
}
