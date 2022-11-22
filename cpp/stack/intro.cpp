#include <bits/stdc++.h>
using namespace std;
class Stack{
    int *arr;
    int size;
    int top;


    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int d){
        if(top < size){
            top++;
            arr[top] = d; 
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            return -1;
        }
    }
};
int main(){
    
}