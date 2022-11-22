#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* leftNode;
    node* rightNode;

    node(int data){
        this -> data = data;
        this -> leftNode = NULL;
        this -> rightNode = NULL;
    }
};

node* buildTree(node* root){

    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    //base condition
    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for the left side" << endl;
    root->leftNode = buildTree(root->leftNode);
    cout << "Enter the data for the right side" << endl;
    root->rightNode = buildTree(root->rightNode);

    return root;
}

void levelorderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            
            if(temp->leftNode){
                q.push(temp->leftNode);
            }
            if(temp->rightNode){
                q.push(temp->rightNode);
            }
        }
    }

}
int main(){
    node* root;

    root = buildTree(root);
    levelorderTraversal(root);
}