#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertAtBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    if(data < root->data){
        insertAtBST(root->left, data);
    }
    else{
        insertAtBST(root->right, data);
    }
}
void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertAtBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";

            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }
    }
}
void preSuc(Node* root, Node* &pre, Node* &suc, int key){
    if(root == NULL){
        return;
    }

    if(root->data == key){
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }
        
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            suc = temp;
        }
    }

    if(root->data > key){
        suc = root;
        preSuc(root->left, pre, suc, key);
    }
    else{
        pre = root;
        preSuc(root->right, pre, suc, key);
    }
}


Node *minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root){
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int key){

    if(root == NULL){
        return root;
    }

    if(root->data == key){

        //1. 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2. 1 child
        // left root
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        //right root
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //3. 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, key);
            return root;
        }
    }

    else if(root->data > key){
        root->left = deleteFromBST(root->left, key);
    }
    else{
        root->right = deleteFromBST(root->right, key);
    }
}

int kthSmallest(Node* root, int k, int &i){
    if(root == NULL){
        return -1;
    }

    int left = kthSmallest(root->left, k, i);;

    if(left != -1){
        return left;
    }

    i++;
    if(i == k){
        return root->data;
    }

    return (root->right, k, i);
}

int kthLargest(Node *root, int k, int &i){
    if(root == NULL){
        return -1;
    }

    int right = kthLargest(root->right, k, i);
    i++;
    if(i == k){
        return root->data;
    } 

    return(root->left, k, i);
}
int main(){
    Node* root = NULL;

    cout << "Enter the data for BST" << endl;
    takeInput(root);

    levelOrderTraversal(root);

    //inorder predessecor
    //inorder successor

    cout << endl; 
    // Node *pre, *suc;
    // int key = 22;
    // preSuc(root, pre, suc, key);
    // cout << pre->data << " " << suc->data << endl;
    //10 8 21 7 27 5 4 3 -1

    // root = deleteFromBST(root, 7);
    // levelOrderTraversal(root);
    int i = 0;
    cout << kthLargest(root, 3, i) << endl;
    cout << kthSmallest(root, 2, i) << endl;
}
