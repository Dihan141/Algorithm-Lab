#include<bits/stdc++.h>

using namespace std;

vector<int> graph[1000];
bool hasVisited[1000];
int colored[1000];

bool DFS(int start)
{
    for(int i=0; i<graph[start].size(); i++)
    {
        int curr = graph[start][i];
        if(!hasVisited[curr])
        {
            hasVisited[curr] = true;
            colored[curr] = !colored[start];
            if(!DFS(curr)) return false;
        }
        if(colored[start] == colored[curr]) return false;
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    int a, b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(hasVisited, false, sizeof(hasVisited));
    memset(colored, 0, sizeof(colored));
    if(DFS(0)) cout<<"BICOLORABLE"<<endl;
    else cout<<"NOT BICOLORABLE"<<endl;
    return 0;
}