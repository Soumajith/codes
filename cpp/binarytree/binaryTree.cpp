#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
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
vector<int> verticalOrder(node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<node*, pair<int,int>>> q;
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            
            pair<node*, pair<int,int>> temp= q.front();
            q.pop();
            
            node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i : nodes){
            for(auto j : i.second){
                for(auto k : j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;                
}

vector<int> topView(node *root)
    {
        vector<int> ans;
        map<int,int> topNode;
        
        queue<pair<node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<node*, int> temp = q.front();
            q.pop();
            
            node* frontNode = temp.first;
            int hd = temp.second;
            
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        
        for(auto i : topNode)
            ans.push_back(i.second);
        
        return ans;
    }
// reverse level order traversal
node* solve(node *root, int &k, int nodes){
    
    if(root == NULL){
        return NULL;
    }
    if(root->data == nodes){
        return root;
    }
    
    node *leftAns = solve(root->left, k, nodes);
    node *rightAns = solve(root->right, k, nodes);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    
}

int kthAncestor(node *root, int k, int nodes)
{
    node *ans = solve(root, k, nodes);
    if(ans == NULL || ans->data == nodes)
        return -1;
    else
        return ans->data;
    
}
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
    root->left = buildTree(root->left);
    cout << "Enter the data for the right side" << endl;
    root->right = buildTree(root->right);

    return root;
}
void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void morrisTraversal(node *root){
    node *curr, *pred;
    if(root == NULL){
        return;
    }

    curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            pred = curr->left;

            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
int main()
{
    node* root;
    root = buildTree(root);
    //ex 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    // levelTraversal(root);
    morrisTraversal(root);
    
}