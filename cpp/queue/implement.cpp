#include <bits/stdc++.h>
using namespace std;
class Queue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
        size = 1e6;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        return front == 0;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Queue overflow"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        else{
            int x = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return x;
        }
    }

    int peek(){
        if(front != rear)
            return arr[front];
    }
};


int main(){
    

}