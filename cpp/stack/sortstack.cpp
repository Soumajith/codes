#include <bits/stdc++.h>
using namespace std;
 
void insertSort(stack<int> &s, int x){
    if( s.empty() || s.top()<x){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertSort(s,x);

    s.push(num);
}
void sort(stack<int> &s){
    //base condition 
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sort(s);

    insertSort(s,num);
}
void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){

    stack<int> s;
    s.push(5);
    s.push(0);
    s.push(6);
    s.push(2);
    s.push(9);

    print(s);

    sort(s);

    print(s);
}