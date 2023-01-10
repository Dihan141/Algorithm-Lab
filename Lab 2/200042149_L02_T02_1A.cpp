#include<bits/stdc++.h>

using namespace std;

int grid[1000][1000];
int hasVisited[1000][1000];

bool isvalid(int x, int y)
{
    if(hasVisited[x][y] || grid[x][y])
        return false;
    return true;
}

bool DFS(int x, int y, int m, int n)
{
    if(!isvalid(x, y)) return true;
    if(x == m-1 || x == 0 || y == n-1 || y == 0) return false;

    hasVisited[x][y] = 1;
    bool left = DFS(x, y-1, m, n);
    bool right = DFS(x, y+1, m, n);
    bool up = DFS(x-1, y, m, n);
    bool down = DFS(x+1, y, m, n);

    return left && right && up && down;
}

int island(int m, int n)
{
    int cnt = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == 0 && hasVisited[i][j])
            {
                if(DFS(i, j, m, n)) cnt++;
            }
        }
    }

    return cnt;
}


int main()
{
    int n, m;
    cout<<"Enter grid size: "<<endl;
    cin>>m>>n;

    memset(hasVisited, 0, sizeof(hasVisited));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];;

    cout<<island(m, n)<<endl;
    return 0;
}