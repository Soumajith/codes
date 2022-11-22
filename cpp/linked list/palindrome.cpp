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
}
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverselist(Node* head){

    Node* curr = head;
    Node* prev = NULL;
    Node* next = curr->next;

    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    return prev;
}
bool isPalindrome(Node* head){
    if(head->next == NULL){
        return 1;
    }
    //find middle
    Node* middle = findMiddle(head);

    //reverse after middle
    Node* temp = middle->next;

    middle->next = reverselist(temp);

    //check with two pointer if same or not
    Node* head1 = head;
    Node* head2 = middle->next; 

    while(head2 != NULL){
        if(head1->data != head2->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next; 
    }

    //back to normal
    temp = middle->next;
    middle->next = reverselist(temp);

    return 1;
}
int main(){
    Node* head = new Node(1);
    insert(head,2);
    insert(head,3);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    // print(head);
    cout<<isPalindrome(head);
}