#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n==0) {
        cout<<-1;
        return 0;
    }
    int set = __builtin_popcount(n);

    if(set>1){
        cout<<-1;
        return 0;
    }

    int pos = 0;
    while(1){
        if(n&1) break;
        pos++;
        n>>=1;
    }
    cout<<pos<<endl;
}