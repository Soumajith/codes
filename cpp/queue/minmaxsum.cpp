#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    for (int i = 0; i < k; i++)
    {
        while(!maxi.empty() && arr[maxi.back()] >= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] <= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;

    for (int i = k; i < n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        //addition
        while(!maxi.empty() && arr[maxi.back()] >= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] <= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        //removal

        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
            
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();
    }
    //last window
    ans += arr[maxi.front()] + arr[mini.front()];
    

    return ans;
    
}
int main(){
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int ans = solve(arr, 7, k);
    cout << ans << endl;
}