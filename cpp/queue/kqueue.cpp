#include <bits/stdc++.h>
using namespace std;
class kQueue{

    public:
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;
    int n, k;

    kQueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];

        front = new int[k];
        rear = new int [k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        freespot = 0;
    }

    void enqueue(int data, int qn){
        //1, check overflow
        if(freespot == -1){
            cout << "Space is not available" << endl;
            return;
        }

        //2. use freespot
        int index = freespot;

        //3. update freespot
        freespot = next[index];

        //3.check is it first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;
        }

        next[index] = -1;

        rear[qn-1] = index;

        arr[index] = data;
    }

    int dequeue(int qn){
        //check underflow
        if(front[qn-1] == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }

        //get the index
        int index = front[qn-1];

        //update the front
        front[qn-1] = next[index];

        //update the free position
        next[index] =  freespot;


        freespot = index;

        //return the value
        return arr[index];
    }

};

int main(){
    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);
    
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;   
    
    cout << q.dequeue(1) << endl; 
}