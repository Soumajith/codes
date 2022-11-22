#include <stdio.h>
int bSearch(int arr[], int n, int key){
    int l =  0;
    int r = n-1;

    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] < key)
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int lSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == n)
            return i;
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the key element to be search: \n");
    int key; scanf("%d",&key);

    printf("Choose your search type:\n");
    printf("1. Binary Search\n2. Linear Search\n");
    int i;
    scanf("%d", &i);
    while(1){
        if(i == 1 || i == 2) break;
        printf("Enter a valid option:\n");
        scanf("%d", &i);
    }
    int ans;
    if(i == 1)
        ans = bSearch(arr, n, key);
    else 
        ans = lSearch(arr, n, key);


    if(ans == -1)
        printf("Element not found\n");
    else
        printf("The Element %d is at %d\n", key, ++ans);
}   