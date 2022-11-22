#include <bits/stdc++.h> 
#include <vector>
   
//    Following is the Binary Tree node structure:

class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };


void inOrderTraversal(TreeNode<int> *root, vector<int> &bst){
    if(root == NULL)
        return;
    inOrderTraversal(root->left, bst);
    bst.push_back(root->data);
    inOrderTraversal(root->right, bst);
}

vector<int> mergeArray(vector<int> &a, vector<int> &b){
    int i = 0, j = 0, k = 0;
    vector<int> ans(a.size() + b.size());
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k] = a[i];
            i++;
            k++;
        }
        else{
            ans[k] = b[j];
            j++;
            k++;
        }
    }
    
    while(i < a.size()){
         ans[k] = a[i];
            i++;
            k++;
    }
    while(j < b.size()){
        ans[k] = b[j];
            j++;
            k++;
    }
    return ans;
}
TreeNode<int> *inOrderToBST(int s, int e, vector<int> &ans){
    if(s > e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    TreeNode<int> *root = new TreeNode<int>(ans[mid]);
    root->left = inOrderToBST(s, mid-1, ans);
    root->right = inOrderToBST(mid+1, e, ans);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> bst1, bst2;
    inOrderTraversal(root1, bst1);
    inOrderTraversal(root2, bst2);
    
    vector<int> mergedArray = mergeArray(bst1, bst2);
    
    return inOrderToBST(0, mergedArray.size()-1, mergedArray);
}

int main(){

}
