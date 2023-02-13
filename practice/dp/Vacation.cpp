#include<bits/stdc++.h>

using namespace std;

long long int a[100001][3];
long long int dp[100001][3];

//with recursion...
// long long int Happiness(long long int n, long long int i)
// {
//     if(n == 0) return a[n][i];
//     if(i == 0)
//         return max(Happiness(n-1, 1) + a[n][0], Happiness(n-1, 2) + a[n][0]);
//     if(i == 1)
//         return max(Happiness(n-1, 0) + a[n][1], Happiness(n-1, 2) + a[n][1]);
//     else
//         return max(Happiness(n-1, 0) + a[n][2], Happiness(n-1, 1) + a[n][2]);
// }

long long int Happiness(long long int n, long long int i)
{
    if(n == 0) return a[n][i];
    if(dp[n][i] != -1) return dp[n][i];
    if(i == 0)
    {
        dp[n][i] = max(Happiness(n-1, 1) + a[n][0], Happiness(n-1, 2) + a[n][0]);
        return dp[n][i];
    }     
    if(i == 1)
    {
        dp[n][i] = max(Happiness(n-1, 0) + a[n][1], Happiness(n-1, 2) + a[n][1]);
        return dp[n][i];
    }     
    else
    {
        dp[n][i] = max(Happiness(n-1, 0) + a[n][2], Happiness(n-1, 1) + a[n][2]);
        return dp[n][i];
    }
        
}

int main()
{
    long long int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
            cin>>a[i][j];
    }
    memset(dp, -1, sizeof(dp));
    long long int mx = max(Happiness(n-1, 0), Happiness(n-1, 1));
    cout<<max(mx, Happiness(n-1, 2))<<endl;
    return 0;
}