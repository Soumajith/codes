#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* buildTree(node* root){
    
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for the left" << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for the right" << endl;
    root->right = buildTree(root->right);

    return root;
}
void inorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root){
    if(root == NULL){
        return;
    }

    
    postorderTraversal(root->left);
    postorderTraversal(root->right);

    cout << root->data << " ";
}
void levelTraversal(node* root){
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
            cout<< temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void buildfromLevelOrder(node* &root){
    queue<node*> q;
    
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    
}

int main(){
    
    node* root;
    // root = buildTree(root);

    // cout << "Inorder traversal "; //LNR
    // inorderTraversal(root);
    // cout << endl;

    // cout << "Preorder traversal "; //NLR
    // preorderTraversal(root);
    // cout << endl;

    // cout << "Postorder traversal ";//LRN
    // postorderTraversal(root);
    // cout << endl;

    buildfromLevelOrder(root);
    levelTraversal(root);

}