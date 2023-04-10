#include<bits/stdc++.h>

using namespace std;

void merge()

void mergeSort(vector<int>& nums, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    return 0;
}