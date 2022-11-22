#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int* arr; 
}Stack;

Stack* createStack(int size){
    
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(Stack* stack){
    return stack->top == stack->size - 1; 
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int data){
    if(isFull(stack)){
        return;
    }
    stack->top += 1;
    stack->arr[stack->top] = data;
    // printf("%d data push into the stack\n",data);
}

int pop(Stack* stack){
    
    if(isEmpty(stack)){
        return -1;
    }

    return stack->arr[stack->top--];
}

int peek(Stack* stack){
    
    if(isEmpty(stack)){
        return -1;
    }

    return stack->arr[stack->top];
}
void insertAtBottom(Stack* stack, int x){
    if(isEmpty(stack)){
        push(stack,x);
        return;
    }

    int num = pop(stack);

    insertAtBottom(stack,x);

    push(stack,num);
}
void reverse(Stack* stack){
    if(isEmpty(stack)){
        // push(stack,num);
        return;
    }
    int num = pop(stack);

    reverse(stack);

    insertAtBottom(stack,num);
}
void print(Stack* stack){
    while(!isEmpty(stack)){
        int x = pop(stack);
        printf("%d\n",x);
    }
}

int main(){
    Stack* stack = createStack(5);

    push(stack,100);
    push(stack,200);
    push(stack,300);
    push(stack,400);
    push(stack,500);
    reverse(stack);

    print(stack);

}