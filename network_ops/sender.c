#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define MYPORT 3490
#define SIZE_TO_SEND 100
//#define MY_IP "127.0.0.1"
#define MY_IP "100.90.240.57"

int main(int argc, char *argv[]) 
{
    int sockfd,sockfd2;
    volatile long long unsigned int a, b;
    long long unsigned int total_cycles=0;
    volatile unsigned hi, lo;
    volatile unsigned hi1, lo1;
    FILE *temp_fp;
    //char tosend[100]; //a char (1byte) to send to receivers
    //char ack[100];
    char* tosend = (char *) malloc(sizeof(char) * atoi(argv[1]));
    int size_buf = sizeof(char) * atoi(argv[1]);
    int send_failed = 0;
    char* ack = (char *) malloc(sizeof(char) * atoi(argv[1]));
    struct sockaddr_in my_addr,rcvr_addr;
    struct timeval start,end;
    int sin_size = sizeof(my_addr),i,k,num_packet_sent,optval;
    double t1,t2;
    memset(tosend, '0', size_buf);

    //open TCP socket,bind and accept RECEIVERS connections 
    if( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) ==-1){
        perror("socket error");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = inet_addr(MY_IP);
    memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));
    //allow reuse of port
    optval = 1;
    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    //bind(socketfd, struct about my address,sizeofmy address);
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        perror("bind");
        exit(1);
    }
    listen(sockfd,10);

    while(1)
    { 
        sockfd2 = accept(sockfd, (struct sockaddr *)&rcvr_addr, &sin_size);
        temp_fp = fopen("temp", "a");

    //connections OK
    //send 100 packet of size 1 byte and for each send wait for ack
        t1=0.0; t2=0.0;
        total_cycles = 0;
//for(num_packet_sent=0;num_packet_sent<100;num_packet_sent++){
        __asm__ __volatile__ ("cpuid");
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        send_failed = send(sockfd2, tosend,size_buf,0);
        optval=recv(sockfd2, ack,size_buf,0);
        //printf("Send status: %d\n", send_failed);
        //printf("Receive status: %d\n", optval);
        __asm__ __volatile__ ("rdtscp" : "=a"(lo1), "=d"(hi1));
        __asm__ __volatile__ ("cpuid");
        a = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
        b = ( (unsigned long long)lo1)|( ((unsigned long long)hi1)<<32 );
        total_cycles += (b-a);
        shutdown(sockfd2,2);
        //printf("%llu \n", total_cycles);
        fprintf(temp_fp, "%llu\n", total_cycles);
        fclose(temp_fp);
    //calculate and print mean rtt
    }
    shutdown(sockfd,2);
    exit(0);
}
