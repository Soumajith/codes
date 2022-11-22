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
        cout<<"Memory freed with value "<<val<<endl;
    }
};
void insertNode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout <<temp -> data << " ";
        temp = temp -> next;
    } while(temp != tail);

    cout << endl;
} 


void deleteNode(Node* &tail, int val){
    if(tail == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        
        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        else if(curr == prev){
            tail = NULL;
        }
        curr->next = NULL;
        delete curr;
    }
}


int main(){
    Node* tail = NULL;
    insertNode(tail, 8, 8);
    insertNode(tail,8,9);
    insertNode(tail,9,2);
    insertNode(tail,2,5);
    insertNode(tail,5,4);
    // deleteNode(tail,8);
    
    print(tail);
}