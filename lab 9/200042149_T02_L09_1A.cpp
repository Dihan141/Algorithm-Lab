#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 205;

const int maxnodes = 100;
int n,pr[110],cap[110][110],reg[110],bd[110];


int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    pr[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(vis[i] or cap[u][i]<=0) continue;
            Q.push(i);
            vis[i]=1;
            pr[i]=u;

        }
    }

    return vis[des];
}
int maxFlow(int src,int des)
{
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=pr[i]) path=min(path,cap[pr[i]][i]);

        for(int i=des; i!=src; i=pr[i])
        {

            int u=pr[i];
            int v=i;

            cap[u][v]-=path;
            cap[v][u]+=path;

        }

        f += path;

    }
    return f;
}



int main()
{
    int tst,cs=0;
    cin>>tst;
    while(tst--)
    {
        memset(cap,0,sizeof(cap));
        int m;
        cin>>n;

        for(int i=1; i<=n; i++){
            cin>>reg[i];
        }

        cin>>m;
        for(int i=1; i<=m; i++){
            int a, b, c;
            cin>>a>>b>>c;

            if(c >= reg[a]){
                cap[a][b] = reg[a];
            }
            else{
                cap[a][b] = c;
            }
        }

        int b, d;
        cin>>b>>d;
        for(int i=1; i<=b+d; i++)
            cin>>bd[i];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<cap[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1; i<=b; i++){
            for(int j=b+1; j<=b+d; j++){
                cout<<maxFlow(bd[i],bd[j])<<endl;
            }
        }
    }

    return 0;
}