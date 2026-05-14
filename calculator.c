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


int main() {
    Stack s;
    char input;
    double num1=0, num2=0;

    //initialize the stack
    initialize_stack(&s);

    // display instructions
    show_instructions();

    // loop to process user input
    while (1) {
        printf("\nEnter instruction: ");
        scanf(" %c", &input);

        switch (input)
        {
            case '?':
                printf("\nEnter Number: ");
                double value;
                if (scanf(" %lf", &value) != 1) {
                    fprintf(stderr, "Error: Invalid number input.\n");
                    break;
                }
                push(&s, value);
                print_stack(&s);
                break;

            case '+':
                if (s.top < 1) {
                    fprintf(stderr, "Error: Not enough operands for addition.\n");
                    break;
                }
                
                num1 = pop(&s);
                num2 = pop(&s);
                printf("Result of %.4f + %.4f = %.4f\n", num2, num1, num1 + num2);
                push(&s, num1 + num2);
                print_stack(&s);
                break;

            case '-':
                if (s.top < 1) {
                    fprintf(stderr, "Error: Not enough operands for subtraction.\n");
                    break;
                }
                num1 = pop(&s);
                num2 = pop(&s);
                printf("Result of %.4f - %.4f = %.4f\n", num2, num1, num2 - num1);
                push(&s, num2 - num1);
                print_stack(&s);
                break;
            
            case '*':
                if (s.top < 1) {
                    fprintf(stderr, "Error: Not enough operands for multiplication.\n");
                    break;
                }
                num1 = pop(&s);
                num2 = pop(&s);
                printf("Result of %.4f * %.4f = %.4f\n", num2, num1, num1 * num2);
                push(&s, num1 * num2);
                print_stack(&s);
                break;
            
            case '/':
                if (s.top < 1) {
                    fprintf(stderr, "Error: Not enough operands for division.\n");
                    break;
                }   
                num1 = pop(&s);
                num2 = pop(&s); 
                if (num1 == 0) {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                    push(&s, num2);
                    push(&s, num1); 
                    break;
                }
                printf("Result of %.4f / %.4f = %.4f\n", num2, num1, num2 / num1);
                push(&s, num2 / num1);
                print_stack(&s);
                break;
                
            case '=':
                if (is_empty(&s)) {
                    fprintf(stderr, "Error: Stack is empty. No result to display.\n");
                    break;
                }
                printf("Top of Stack (Result): %.4f\n", peek(&s));
                break;
                
            case 'p':
                print_stack(&s);
                break;

            case 'q':
                printf("Exiting the calculator. Goodbye!\n");
                printf("Press Enter to exit...");
                getchar(); 
                getchar(); 
                return 0;

            default:
                printf("Invalid instruction.\n");
                show_instructions();
                break;
        }
    }
    printf("Exiting the calculator. Goodbye!\n");

    return 0;
    
}