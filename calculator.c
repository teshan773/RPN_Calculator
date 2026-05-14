#include <stdio.h>
#include <stdlib.h>

//Maximum size of the stack
#define MAX_STACK_SIZE 100  

typedef struct {
    double data[MAX_STACK_SIZE];
    int    top;               
} Stack;

// initialize the stack
void initialize_stack(Stack *s) {
    s->top = -1;
}

// check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// check if the stack is full
int is_full(Stack *s){
    return s->top == MAX_STACK_SIZE - 1;
}

// push a new value into the stack
int push(Stack *s, double value) {
    if (is_full(s)) {
        fprintf(stderr, "Error: Stack overflow. Cannot push %.4f.\n", value);
        return 0;
    }
    s->data[++(s->top)] = value;
    return 1;
}