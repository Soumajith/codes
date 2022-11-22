#include <bits/stdc++.h>
using namespace std;

class TrieNode{

   public:
    char data;
    TrieNode* childern[26];
    bool isTerminal;

    TrieNode(char d){
        data = d;
        for (int i = 0; i < 26; i++)
            childern[i] = NULL;
        
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        //base case 
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> childern[index] != NULL){
            child = root->childern[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childern[index] = child;
        }

        //Recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string wood){
        insertUtil(root, wood);
    }

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }


        int index = word[0] - 'A';
        TrieNode* child;
        //present
        if(root->childern[index] != NULL){
            child = root->childern[index];
        }
        //absent
        else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);    
    }
};




int main(){
    Trie* t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("TOOTH");

    cout << t->searchWord("ABCD");
}