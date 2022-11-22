#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed of value "<<val<<endl;
    }
};
void insert(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node* head = new Node(1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    Node* head2 = new Node(1);
    insert(head2,2);
    insert(head2,3);
    insert(head2,4);
    insert(head2,5);
    insert(head2,6);
    insert(head2,7);
    print(head);
    print(head2);
 
    head = mergelist(head, head2);
    print(head);
}