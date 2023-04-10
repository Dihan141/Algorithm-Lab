#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> matrix[16];
int dp[1<<16][16];

bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}
int turnOn(int N,int pos)
{
    return (N | (1<<pos));
}

int PossibleWays(int mask, int k)
{
    if(mask == (1<<n)-1) return 1;
    if(dp[mask][k] != -1) return dp[mask][k];
    int total = 0;
    for(int i=0; i<n; i++)
    {
        if(!isOn(mask, i) && matrix[k][i] != 0)
        {
            total += (PossibleWays(turnOn(mask, i), k+1))%(1000000007);
        }
    }
    dp[mask][k] = total;
    return dp[mask][k];
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            matrix[i].push_back(x);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout<<PossibleWays(0, 0)<<endl;
    return 0;
}