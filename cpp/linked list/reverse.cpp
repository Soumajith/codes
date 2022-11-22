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

};
void insertAtHead(Node* &head, int d){
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
    }
    else{
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(Node* &head, int d){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(d);
    temp->next = newNode;

}
void insertAtPos(Node* &head, int d, int pos){
    int ct=1;
    if(pos == 1){
        return insertAtHead(head,d);
    }

    Node* curr = head;
    Node* prev = head;
    while(ct != pos){
        prev = curr;
        curr = curr->next;
        ct++;
    }
    Node* newNode = new Node(d);
    newNode->next = curr;
    prev->next = newNode;
}
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* reversal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* subhead = reversal(head->next);
    head->next->next = head;
    head->next = NULL;
    return subhead;

}
Node* reverselist(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverse(Node* &head, Node* curr, Node* prev){

    //base condition
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;

    reverse(head, forward, curr);

    curr->next = prev;
}
Node* middleElement(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    
    if(head->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow= slow->next;
    }

    return slow;
}
Node* kreverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    Node* forward = NULL;
    Node* curr = head;
    Node* prev= NULL;
    int count = 0;

    while(curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = kreverse(forward, k);
    }

    return prev;
}
int main(){
    Node* head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 9);
    insertAtHead(head, 0);
    // insertAtHead(head, 2); 
    insertAtHead(head, 11);
    insertAtPos(head,4, 2);
    insertAtTail(head,8);
    print(head);
    head = reverselist(head);
    // head = reversal(head);
    Node* temp = middleElement(head);
    cout<<temp->data<<endl;

    print(head);

}