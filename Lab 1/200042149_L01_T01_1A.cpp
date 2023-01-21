#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int adjMat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>adjMat[i][j];
    }

    int celeb = -1;
    int index = -1;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        int j = 0;
        for(j=0; j<n; j++)
        {
            if(adjMat[j][i] == 1)
            {
                cnt++;
            }
        }
        if(cnt == n)
        {
            celeb = i;
            index = j;
            break;
        }
    }

    if(celeb == -1)
    {
        cout<<"There is no celebrity."<<endl;
    }
    else
    {
        int flg = 0;
        for(int i=0; i<n; i++)
        {
            if(celeb != i)
            {
                if(adjMat[index][i] == 1)
                {
                    flg = 1;
                    break;
                }
            }
        }

        if(flg)
            cout<<"There is no celebrity."<<endl;
        else
            cout<<"Person "<<celeb<<" is the celebrity"<<endl;
    }
    return 0;
}