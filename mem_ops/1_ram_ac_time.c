#include "c_linked.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define R_1 runner = runner -> next;
#define R_2 R_1 R_1
#define R_4 R_2 R_2
#define R_8 R_4 R_4
#define R_16 R_8 R_8
#define R_32 R_16 R_16
#define R_64 R_32 R_32
#define R_128 R_64 R_64
#define R_256 R_128 R_128
#define R_512 R_256 R_256
#define R_1024 R_512 R_512
#define R_2048 R_1024 R_1024
#define R_4096 R_2048 R_2048
#define R_8192 R_4096 R_4096
long long unsigned int countMem;
void create_list(struct node *head, long long unsigned int num_nodes){
    long long unsigned int i = 0;
    struct node *temp = head;
    for(i = 0; i < num_nodes; i++){
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        temp->next = new_node;
        temp = temp->next;
        countMem += (int)sizeof(struct node);
    }
    temp->next = head;
}
int main(int argc, char** argv){
    countMem = 0;
    struct node *head = (struct node *) malloc(sizeof(struct node));
    long long unsigned int num_nodes_log2 = (long long unsigned int)atoi(argv[1]);
    long long unsigned int num_nodes = pow(2, num_nodes_log2);
    
    volatile long long unsigned int a, b;
    long long unsigned int total_cycles=0;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    long long unsigned int i = 0;
    struct node *runner = head;
    create_list(head, num_nodes);
    for(i = 0; i < 5*num_nodes; i++){
        R_128
        total_cycles += (b-a);
    }
    total_cycles = 0;
    for(i = 0; i < 100000; i++){
        __asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        R_128
        __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
        __asm__ __volatile__ ("cpuid");
        a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
        b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
        total_cycles += (b-a);
    }
    printf("%llu %llu %d %lf\n", num_nodes, countMem, (int)sizeof(struct node), 1.0* total_cycles/(100000));
    return 0;
}

