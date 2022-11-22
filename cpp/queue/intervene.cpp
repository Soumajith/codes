#include <bits/stdc++.h>
using namespace std;
void intervene(queue<int> &q){
    stack<int> s;
    int n = q.size();
    for(int i = 0; i < n/2; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    for(int i = 0; i < n/2; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for(int i = 0; i < n/2; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
}
void print(queue<int>q){
    while(!q.empty()){
        int val = q.front();
        q.pop();
        cout << val << endl;
    }
}
int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    print(q);
    cout << endl;
    intervene(q);
    print(q);
}