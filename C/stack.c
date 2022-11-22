#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int top;
    int arr[100];
}stack;

int push(int a, stack* x){
    if(x->top==100){
    return 0;
    }
    else {
        x->top += 1;
        x->arr[x->top] = a;
        return 1;
    }   
}

int pop(stack* x, int* a){
    if(x->top==1){
        return 0;
    } 
    else {
    *a = x->arr[x->top];
    x->top -=1;
    return 1;
    }
    
}
int main(){
    stack *x =(stack*)malloc(sizeof(stack));
    int i = push(2,x);
    i = push(5,x);
    i = push(9,x);
    int *a;
    i = pop(x,a);
    printf("%d\n",*a);
    i = pop(x,a);
    printf("%d\n",*a);
    i = pop(x,a);
    printf("%d\n",*a);
    
}

