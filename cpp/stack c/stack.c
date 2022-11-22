#include <stdio.h>
#include <stdlib.h>

typedef struct stackelement
{
    int item;
    struct stackelement *next;
}stackelement;

stackelement *top = NULL;

void push(int a){
    stackelement *x;
    x = (stackelement*)malloc(sizeof(stackelement)); 
    x->item = a;
    if(top == NULL){
        x->next = NULL;
    }
    else{
        x->next = top;
    }
    
    top = x;
    printf("Node inserted\n");
}

int pop(int *a){
    stackelement *t;
    if(top == NULL){
        printf("Empty list\n");
        a = NULL;
        return 0;
    }
    t = top;
    *a = t->item;
    top = top->next;
    free(t);
    return 1;
}

int main(){
    int *i;
    
    push(10);
    push(20);
    int a = pop(i);
    printf("%d",*i);
    // i = pop(a, s);
 
}