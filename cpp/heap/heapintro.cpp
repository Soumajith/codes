#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int d){
        size += 1;
        int index = size;
        arr[index] = d;
        
        
        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print(){
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        
        cout << endl;
    }
    
    void deleteHeap(){
        if(size == 0)
            return;

        arr[1] = arr[size];
        size--;
        int i = 1;

        while(i <= size){
            int left = 2*i;
            int right = 2*i + 1;

            if(left <= size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right <= size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }
            else return;
        }
    }
};
// this function checks the root node with child node swaps if necessary and it skips the leaf node it traverse from n/2+1 to n
void heapify(int arr[], int n, int i){

    int left = 2*i;
    int right = 2*i + 1;
    int largest = i;
    
    if(left <= n && arr[largest] < arr[left])
        largest = left;
    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n){
    
    int size = n;
    
    while(size > 1){
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}
//    Node = ith  index
//    left child = 2*i
//    right child = 2*i + 1
//    parent node = i/2
int main(){

    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.deleteHeap();
    // h.print();

    int a[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // for(int i = n/2; i > 0; i--)
    //     heapify(a, n, i);

    //heapsort
    heapSort(a, n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    
    cout << endl;


    //maxHeap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(7);
    pq.push(6);
    pq.push(9);
    pq.push(0);

    cout << "Top of Max Heap " << pq.top() << endl;
    pq.pop();
    cout << "Top of Max Heap " << pq.top() << endl;

    //minHeap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(4);
    minpq.push(0);
    minpq.push(9);
    minpq.push(2);
    minpq.push(1);
    minpq.push(5);

    cout << "Top of Min Heap " << minpq.top() << endl;
    minpq.pop();
    cout << "Top of Min Heap " << minpq.top() << endl;
}