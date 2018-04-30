//
//  main.c
//  demandPagedMemory
//
//  Created by Adarsh Pawar on 12/04/18.
//  Copyright © 2018 Adarsh Pawar. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    float prob1 = 0.7, prob2 = 0.3;
    double long p;              //P is page fault rate
    long t1 = 100, t2 = 20000000 , t3 = 8000000, tmax = 200; //time is in neno sec an milli sec
    printf("Let p be the page fault rate (the probability that a memory access results in a page fault)\n");
    printf("Then (1 − p) is the probability that a memory access costs 100 nsec.\n");
    printf("The probability that a page fault costs %ld is %f ∗ p and the probability that a page fault costs %ld is %f ∗ p.\n",t2,prob1,t3,prob2);
    printf("Since 1 nsec = 1000000 msec,\n");
    p = (tmax-t1)/((prob1*t2)+(prob2*t3)-t1);
    printf("%Lf will be the page fault rate.\n",p);
    printf("%Lf persentage\n",p*100);
}
