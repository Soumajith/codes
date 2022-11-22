#include <bits/stdc++.h>
using namespace std;
bool checkbalanced(string expression){
    stack<char>s;

    for (int i = 0; i < expression.length(); i++)
    {

        //if opening bracket push
        //else closing backet then check and pop
        char ch = expression[i];
        
            if(ch == '(' ||ch == '{' ||ch == '['){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char top = s.top();
                    if((top == '(' && ch == ')')|| (top == '{' && ch == '}')||(top == '[' && ch == ']')){
                        s.pop();
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
        
    }
    if(s.empty()){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    
    string expression = "[{()}]"; 
    cout<<checkbalanced(expression);
}