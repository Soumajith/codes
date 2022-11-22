#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNodes(struct Node* head, int n){
    for(int i = 0; i < n; i++){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &temp->data);
        temp->next = head;
        head = temp; 
    }
    return head;
}
struct Node* insertAtHead(struct Node* head, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}
int search(struct Node* head, int key){
    int i = 0;
    while (head != NULL)
    {
        i++;
        if(head->data == key)
            return i;
        
        head = head->next;
    }
    return -1;
}
void print(struct Node* head){
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    struct Node* head = NULL;
    // head = insertAtHead(head, 1);
    // head = insertAtHead(head, 3);
    // head = insertAtHead(head, 5);
    // head = insertAtHead(head, 6);

    head = createNodes(head, 5);
    print(head);
    printf("Enter the element to be search\n");
    int key; scanf("%d",&key);
    int i = search(head, key);
    if(i == -1)
        printf("Element not found\n");
    else
        printf("Element found at %d\n", i);

    //1. Create
    //2. Insertion
    //3. Deletion
    //4. reverse
    //5. Circular LL
    
}