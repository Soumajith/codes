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
        this->next = NULL;
        cout<<"Memory freed of value at "<<val<<endl;
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
map<Node*, bool>visited;
bool detectCycle(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"Cycle is present at "<<temp->data<<endl;
            return true;
        }
        visited[temp]= true;
        temp = temp->next;
    }
    return false;
}
//flyod cycle detection algorithm
Node* flyodDetection(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            cout<<"Loop present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head){
    if(head == NULL)
        return NULL;

    Node* intersection = flyodDetection(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}
void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* start = getStartingNode(head);
    Node* temp = start;
    while(temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(){
    Node* head = NULL;
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,6);
    Node* a = new Node(8);
    head->next->next->next = a;
    Node* b = new Node(2);
    a->next = b;
    Node* c = new Node(9);
    b->next = c;
    c->next = head->next;

    if(flyodDetection(head) != NULL){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    Node* temp = getStartingNode(head);
    cout<<"Loop starts at "<<temp->data<<endl;

    removeLoop(head);
    print(head);
}