#include <stdio.h>
#include <stdlib.h>
#include "c_linked.h"
#define READ_ONE __asm__ __volatile__ ("cpuid");\
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));\
    sum += runner->data;\
    runner = runner->next;\
    __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));\
    __asm__ __volatile__ ("cpuid");\
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );\
    b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );\
    total += b-a;
#define READ_FIVE READ_ONE READ_ONE READ_ONE READ_ONE READ_ONE
#define READ_TEN READ_FIVE READ_FIVE
#define READ_HUN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN READ_TEN 
#define READ_THD READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN READ_HUN
#define WRITE_ONE __asm__ __volatile__ ("cpuid"); \
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));\
    runner->data = (runner - runner->next)/1000; \
    runner = runner->next;\
    __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));\
    __asm__ __volatile__ ("cpuid");\
    runner = runner->next;\
    a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );\
    b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );\
    total += b-a;
#define WRITE_FIVE WRITE_ONE WRITE_ONE WRITE_ONE WRITE_ONE WRITE_ONE
#define WRITE_TEN WRITE_FIVE WRITE_FIVE
#define WRITE_HUN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN WRITE_TEN 
#define WRITE_THD WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN WRITE_HUN
void create_list(struct node *head, long long unsigned int num_nodes){
    long long unsigned int i = 0;
    struct node *temp = head;
    for(i = 0; i < num_nodes; i++){
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        temp->next = new_node;
        temp = temp->next;
    }
    temp->next = head;
}
int main(){
    int sum = 0;
    volatile long long unsigned int a, b;
    volatile long long unsigned int total;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    struct node *runner = head;
    total = 0;
    create_list(head, 1000);
    WRITE_THD
    printf("%llu cycles ", total);
    total = 0;
    READ_THD
    printf("%llu cycles\n", total);
    return 0;
}
