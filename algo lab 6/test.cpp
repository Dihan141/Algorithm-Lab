#include<bits/stdc++.h>

using namespace std;

bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}
int turnOn(int N,int pos)
{
    return (N | (1<<pos));
}

int main()
{
    int n = 1<<16;
    cout<<turnOn(0,1)<<endl;
    return 0;
}