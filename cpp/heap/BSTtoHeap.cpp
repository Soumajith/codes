#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
};
void inorder(Node* root, vector<int> &arr){
    if(root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void BSTtoHeap(Node* root, vector<int> &arr, int &i){

    if(root == NULL)
        return;

    root->data = arr[i++];
    BSTtoHeap(root->left, arr, i);
    BSTtoHeap(root->right, arr, i);
}


int main(){
    Node* root;
    //Bst to array inorder traversal
    vector<int> arr;

    inorder(root, arr);
    //using pre order traversal change the array values
    int index = 0;
    BSTtoHeap(root, arr, index);
}