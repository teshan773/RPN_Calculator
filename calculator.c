#include <stdio.h>
#include <stdlib.h>

//Maximum size of the stack
#define MAX_STACK_SIZE 100  

typedef struct {
    double data[MAX_STACK_SIZE];
    int    top;               
} Stack;