#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
 void findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> indegree;
    for(int i=0; i<prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i=0; i<numCourses; i++)
    {
        indegree[i] = 0;
    }

    for(auto vertex: graph)
    {
        for(auto neighbour: vertex.second)
        {
            indegree[neighbour]++;
        }
    }

    for(auto vertex: indegree)
    {
        cout<<vertex.first<<"--"<<vertex.second<<endl;
    }

    queue<int> zero_indegrees;
    for(auto vertex: indegree)
    {
        if(vertex.second == 0)
            zero_indegrees.push(vertex.first);
    }

    while(!zero_indegrees.empty())
    {
        int vertex = zero_indegrees.front();
        zero_indegrees.pop();
        ans.push_back(vertex);
        for(auto neighbour: graph[vertex])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                zero_indegrees.push(neighbour);
        }
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
 }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{1,0}};
    sol.findOrder(3, v);
    return 0;
}