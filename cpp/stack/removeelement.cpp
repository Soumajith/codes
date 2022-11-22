#include <bits/stdc++.h>
//remove element from the middle of the stack
using namespace std;
void remove(stack<int> &s, int count, int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    remove(s,count+1,size);

    s.push(num);
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    remove(s,0,s.size());
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}