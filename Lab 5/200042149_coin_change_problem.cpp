#include<bits/stdc++.h>

using namespace std;

int dp[250][250];
int a[50];
int m;
int cnt = 0;

bool CoinChange(int n, int j)
{
    if(n == 0) return true;
    if(n < 0 || j==m-1) return false;

    if(CoinChange((n-a[j]), j)) cnt++;
    else if(CoinChange(n, j+1)) cnt++;
    return false;
}

int main()
{
    int n;
    cin>>n>>m;

    for(int i=0; i<m; i++)
        cin>>a[i];

    bool ans = CoinChange(n, 0);
    cout<<cnt+1<<endl;
    return 0;
}