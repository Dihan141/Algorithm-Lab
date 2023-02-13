#include<bits/stdc++.h>

using namespace std;

long long int cnt[100005] = {0};
long long int dp[100005];

long long int boredomDP(long long int m)
{
    if(dp[m] == 0) return 0;
    if(dp[m] == 1) return dp[m];
    if(dp[m] != -1) return dp[m];
    dp[m] = max(boredomDP(m-1), boredomDP(m-2) + cnt[m]*m);
    return dp[m];
}

int main()
{
    long long int n, a, mx = 0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        cnt[a]++;
        mx = max(mx, a);
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = cnt[1];
    cout<<boredomDP(mx)<<endl;
    return 0;
}