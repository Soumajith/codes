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
Node* reverselist(Node* head){

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void print(Node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    cout<<endl;
}
Node* add(Node* first, Node* second){
    int carry = 0;
    Node* ans = NULL;
    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;
        if(first != NULL)
            val1 = first->data;
        
        int val2 = 0;
        if(second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2; 
        int digit = sum%10;
        carry = sum/10;
        insert(ans,digit);
        if(first != NULL)
            first = first->next;
        
        if(second != NULL)
            second = second->next;
    }
    return ans;
}
Node* addlist(Node* first, Node* second){
    first = reverselist(first);
    second = reverselist(second);

    Node* add_head = add(first,second);

    return add_head;
}
int main(){
    Node* first = new Node(0);
    insert(first,9);
    insert(first,3);
    print(first);
    
    Node* second = new Node(5);
    insert(second,4);
    print(second);

    Node* head = addlist(first,second);
    print(head);
}