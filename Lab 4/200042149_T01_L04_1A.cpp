#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> graph[n];
    int dist[n];
    int cost[n][n];
    memset(cost, 0, sizeof(cost));

    int src, dest, roadCost;
    for(int i=0; i<m; i++)
    {
        cin>>src>>dest>>roadCost;
        src--;
        dest--;
        if(cost[src][dest])
        {
            cost[src][dest] = min(cost[src][dest], roadCost);
            cost[dest][src] = cost[src][dest];
        }
        else
        {
            graph[src].push_back(dest);
            graph[dest].push_back(src);
            cost[src][dest] = roadCost;
            cost[dest][src] = roadCost;
        }
    }

    int mnCost = INT_MAX;
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
            dist[i] = INT_MAX;

        queue<int> que;
        que.push(k);
        dist[k] = 0;

        while(!que.empty())
        {
            int start = que.front();
            que.pop();
            for(int i=0; i<graph[start].size(); i++)
            {
                int curr = graph[start][i];
                // cout<<"cost "<<start<<" to "<<curr<<" "<<cost[start][curr]<<endl;
                // cout<<"max "<<maxCost<<endl;
                if(dist[start] + cost[start][curr] < dist[curr])
                {
                    // cout<<"working"<<endl;
                    dist[curr] = dist[start] + cost[start][curr];
                    que.push(curr);
                }
            }
        }

        int sum = 0;
        for(int i=0; i<n; i++)
            sum += dist[i];

        if(sum <= mnCost)
        {
            cout<<k+1<<endl;
            mnCost = sum;
        }
    }
    return 0;
}