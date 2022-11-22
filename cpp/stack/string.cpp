#include <bits/stdc++.h>
//reverse a string using a stack
using namespace std;
int main(){
    stack<char>s;
    string str = "soumo";
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    cout<<ans<<endl;
}