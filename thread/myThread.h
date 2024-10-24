#ifndef C_MYTHREAD_H
#define C_MYTHREAD_H
#include "include.h"

#define MAXTHREADS 1000

typedef struct{
    int processID;
    
} PCB;

void checkThread();

int printHello(int n);

#endif // C_MYTHREAD_H
