#include<bits/stdc++.h>

using namespace std;


//recursive shit
long long int CoinsR(long long int n)
{
    if(n < 12) return n;
    return CoinsR(n/2) + CoinsR(n/3) + CoinsR(n/4);
}


int main()
{
    long long int n;
    while(cin>>n)
    {
        cout<<CoinsR(n)<<endl;
    }
    return 0;
}