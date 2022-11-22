#include <bits/stdc++.h>
using namespace std;
int setbitcount(int n)
{
    int ct = 0;
    for (int i = 1; i <= 32; i++)
    {
        if (n & 1)
        {
            ct++;
            n >>= 1;
        }
        else
        {
            n >>= 1;
        }
    }
    return ct;
}
int main(){
    int n;
    cin>>n;
    cout<<setbitcount(n)<<endl;
}