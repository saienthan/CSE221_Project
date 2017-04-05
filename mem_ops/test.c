#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define R_1 itr = itr -> next;
#define R_2 R_1 R_1
#define R_4 R_2 R_2
#define R_8 R_4 R_4
#define R_16 R_8 R_8
#define R_32 R_16 R_16
#define R_64 R_32 R_32
#define R_128 R_64 R_64

struct node {
    struct node *next;
};


char *myconcat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(int argc, char** argv) {

    uint32_t time_start = 0;
    uint32_t time_end   = 0;
    uint32_t sum_time = 0;
    volatile long long unsigned int a, b;
    long long unsigned int total_cycles;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;


    int ll_size = atoi(argv[1]), i;

    // printf("size of struct = %d\n", sizeof(struct node));

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *itr = head;

    for(i = 0; i < ll_size - 1; i ++){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        itr -> next = temp;
        itr = itr -> next;
    }

    itr -> next = head;
    itr = head;

    for(i = 0; i < 1000000; i++){

		__asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        R_128
        __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
        __asm__ __volatile__ ("cpuid");
        a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
        b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
        total_cycles += b-a;



    }


    printf("%llu\n", total_cycles / 1000000);

    return 0;
}
