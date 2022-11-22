#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* create(int n){
 Node* head,*prev,*temp;
 int i;
 head = (Node*)malloc(sizeof(Node));
 scanf("%d",&(head->data));
 head-> next = NULL;
  prev = head;
  for(i =0;i< n-1;i++){
    temp= (Node*)malloc(sizeof(Node));
    scanf("%d",&(temp->data)); 
    temp-> next = NULL;
    prev->next = temp;
    prev = temp;

  }
  return head;
}


void print ( Node* head)
{
    Node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
int main()
{
    Node* head = create(6);
    print(head);
}