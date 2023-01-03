#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n][n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];

    queue<int> que;
    int hasVisited[n];
    for(int k=0; k<n; k++)
    {
        hasVisited[k] = 0;
    }

    int province = 0;
    for(int k=0; k<n; k++)
    {
        if(hasVisited[k] == 0)
        {
            province++;
            que.push(k);
            hasVisited[k] = 1;
        }

        while(!que.empty())
        {
            int i = que.front();
            que.pop();

            for(int j=0; j<n; j++)
            {
                if(a[i][j] == 1)
                {
                    if(!hasVisited[j])
                    {
                        que.push(j);
                        hasVisited[j] = 1;
                    }
                }
            }
        }
    }
    cout<<province<<endl;
    return 0;
}