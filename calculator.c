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

// pop a value from the stack
double pop(Stack *s){
    if (is_empty(s)){
        fprintf(stderr, "Error: Stack underflow. Cannot pop from an empty stack.\n");
        return 0;
    }
    double result = s->data[(s->top)--];
    return result;
}

// get top value of the stack without removing it
double peek(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Error: Stack is empty. Cannot peek.\n");
        return 0;
    }
    double result = s->data[s->top];
    return result;
}

// print the current stack
void print_stack(Stack *s) {
    printf("Current Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%.4f ", s->data[i]);
    }
    printf("\n");
}

void show_instructions() {
    printf("========================================\n");
    printf("  Reverse Polish Notation Calculator\n");
    printf("========================================\n");
    printf("Instructions:\n");
    printf("  ?  - Enter a number\n");
    printf("  +  - Addition\n");
    printf("  -  - Subtraction\n");
    printf("  *  - Multiplication\n");
    printf("  /  - Division\n");
    printf("  =  - Print Result\n");
    printf("  q  - Quit\n");
    printf("  p  - Print Stack\n");
    printf("----------------------------------------\n");
}
