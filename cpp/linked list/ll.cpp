#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;


    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    //deconstructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed of "<<val<<endl;
    }
};
void print(Node* head){
    Node* temp = head;

    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
int length(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!= NULL){
        temp= temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insert(Node* &head, Node* &tail, int position, int val){
    if(position == 1){
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    int ct = 1;
    while(ct<position-1){
        temp = temp->next;
        ct++;
    }
    if(temp->next == NULL){
        insertAtTail(temp, val);
    }
    
    Node* insertNode = new Node(val);
    
    insertNode->next = temp->next;
    temp->next->prev = insertNode;
    temp->next = insertNode;
    insertNode->prev = temp;

}
void deleteNode(Node *&head, int pos){
    if(pos==1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int ct = 1;
        while(ct < pos){
            prev = curr;
            curr = curr->next;
            ct++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        // prev->next->prev = prev;
        curr->next = NULL;
        free(curr);
        
    }
}
int main(){
    Node* n1 = new Node(19);
    Node* head = n1;
    Node* tail = n1;
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtTail(tail, 12);
    insert(head, tail, 2, 100);
    deleteNode(head,1);
    deleteNode(head, 6);
    cout<<tail->data<<endl;

    print(head);
}