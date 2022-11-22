#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            this->next = NULL;
            cout<<"Node is deleted with value"<<val<<endl;

        }
    }

};

void insert(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* removeDuplicates(Node* head){
    //empty list
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        
        if(curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* duplicateNode = curr->next;
            curr->next = next_next;
            delete(duplicateNode);
        }
        else{
            curr= curr->next;
        }
    }
    return head;
}
Node* removeDup(Node* head){
    Node* curr = head;
    map<int,bool> visited;    
    Node *prev = NULL;
    while(curr!=NULL){
        
        if(visited[curr->data]){
            Node* deleteNode = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(deleteNode);
        }
        else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main(){
    Node* head = new Node(10);
    insert(head,11);
    insert(head,12);
    insert(head,11);
    insert(head,12);
    insert(head,13);
    insert(head,12);
    insert(head,14);
    print(head);
    head = removeDup(head);
    print(head);
    
}