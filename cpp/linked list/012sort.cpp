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
Node* sort(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }
        else if(temp->data == 1){
            oneCount++;
        }
        else if(temp->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){

        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}
void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}
Node* sortHead(Node* head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        int val = curr->data;
        if(val == 0){
            insertAtTail(zeroTail,curr);
        }
        else if(val == 1){
            insertAtTail(oneTail, curr);
        }
        else if(val == 2){
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    Node* head = new Node(0);
    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,0);
    insert(head,1);
    insert(head,1);
    print(head);
    cout<<endl;
    head = sortHead(head);
    print(head);

}