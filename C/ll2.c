#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void push(Node** head, int new_data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}
void print(Node* head_ref){
    while (head_ref->next != NULL)
    {
        printf("%d ",head_ref->data);
        head_ref = head_ref->next;
    }
}

void deleteN(Node** head,int position){
    Node* temp;
    Node* prev;
    temp = *head;
    prev = *head;

    for (int i = 0; i < position; i++)
    {
        if(i==0 && position==1){
            *head = (*head)->next;
            free(temp);
        }
        else{
            if(i == position-1 && temp){
                prev->next = temp->next;
                free(temp);
            }
            else{
                prev = temp;

                if(prev == NULL) break;
                temp = temp->next;
            }
        }
    }
}

void deleteKey(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev;

    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp->next != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void duplicates(Node* head){
    Node *ptr1, *ptr2, *del;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2=ptr1;
        while (ptr2->next != NULL)
        {
            if(ptr1->data == ptr2->next->data){
                del = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(del);
            }
            else
                ptr2 = ptr2->next;
            
        }
        ptr1 = ptr1->next;
    }
}

//delete N nodes after M nodes
void deleteMN(Node* head, int m, int n){
    Node *t, *curr = head;
    int count;

    while(curr){
        
        for(count = 1; count<m && curr!= NULL; count++){
            curr = curr->next;
        }

        if(curr == NULL)
            return;
        
        t = curr->next;

        for(count=1; count<=n && t!=NULL;count++){
            Node* temp = t;
            t = t->next;
            free(temp);
        }

        curr->next = t;

        curr = t;
    }
     
}

//recursion
void deleteR(Node* head, int key){
    if(head == NULL){
        printf("List doesnt exist\n");
        return;
    }

    if(head->data == key){
        Node* temp = head;
        head = head->next;;

        free(temp);
        return;
    }

    deleteR(head->next, key);
}
int main(){
    Node* head = malloc(sizeof(Node));
    head->next = NULL; 
    push(&head,9);
    push(&head,0);
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    // duplicates(head);
    deleteMN(head, 1, 1);
    print(head);
}

