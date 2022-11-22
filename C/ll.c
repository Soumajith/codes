#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void printlist(struct Node **head_ref){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = *head_ref;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void append(struct Node** head,int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node; 
}
void insertAfter(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("Cant insert\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->next = prev_node->next;
    new_node->data = new_data;
    prev_node->next = new_node;

}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data =  new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
int main(){
    struct Node* head = NULL;
    push(&head,8);
    push(&head,4);
    push(&head,5);
    push(&head,0);
    append(&head,10);
    insertAfter(head->next->next, 19);
    printlist(&head);
}