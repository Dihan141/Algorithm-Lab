#include<bits/stdc++.h>

using namespace std;

int n;
int mixtures[100];
int color[100][100];
int dp[100][100];

int smokeAmount(int i, int j)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i; k<j; k++)
    {
        dp[i][j] = min(dp[i][j], smokeAmount(i, k) + smokeAmount(k+1,j) + color[i][k]*color[k+1][j]);
    }

    return dp[i][j];
}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>mixtures[i];
    }

    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
        color[i][i] = mixtures[i];

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            color[i][j] = (mixtures[i] + mixtures[j])%100;
            color[j][i] = color[i][j];
        }
    }

    cout<<smokeAmount(0, n-1)<<endl;
    return 0;
}