#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* reverselist(Node* head){
    Node *prev, *curr, *forw;
    prev = NULL;
    curr = head;
    forw = curr->next;
    while(curr->next != NULL){
        curr->next = prev;
        prev = curr;
        curr = forw;
        forw = curr->next;
    }
    curr->next = prev;
    return curr;
}

void traversal(Node *head){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    Node *temp;
    temp = head;
    while(head != NULL){
        printf("%d ",(head->data));
        head = head->next;
    }
    printf("\n");
    head = temp;
}

int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *first = (Node*)malloc(sizeof(Node));
    Node *second= (Node*)malloc(sizeof(Node));
    head->data = 7;
    head->next = first;
    first->data = 6;
    first->next = second;
    second->data = 5;
    second->next = NULL;
    head = reverselist(head);
    
}
