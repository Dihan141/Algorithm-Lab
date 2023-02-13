#include<bits/stdc++.h>

using namespace std;

long long int k1, k2;
long long int dp[101][101][11][11];

// long long int legion(long long int n1, long long int n2, long long int l1, long long int l2)
// {
//     if(l1 < 0 || l2 < 0) return 0;
//     if(n1 == 0 && n2 == 0) return 1;    
//     if(n1 < 0 || n2 < 0) return 0;
//     return (legion(n1-1, n2, l1-1, k2) + legion(n1, n2-1, k1, l2-1))%100000000;
// }

long long int legionDP(long long int n1, long long int n2, long long int l1, long long int l2)
{
    if(l1 < 0 || l2 < 0) return 0;
    if(n1 == 0 && n2 == 0) return 1;    
    if(n1 < 0 || n2 < 0) return 0;
    if(dp[n1][n2][l1][l2] != -1) return dp[n1][n2][l1][l2];
    dp[n1][n2][l1][l2] = (legionDP(n1-1, n2, l1-1, k2) + legionDP(n1, n2-1, k1, l2-1))%100000000;
    return dp[n1][n2][l1][l2];
}

int main()
{
    long long int n1, n2;
    cin>>n1>>n2>>k1>>k2;

    memset(dp, -1, sizeof(dp));
    cout<<legionDP(n1, n2, k1, k2)<<endl;
}