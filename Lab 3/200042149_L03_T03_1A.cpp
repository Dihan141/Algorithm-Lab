#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    queue<Node*> que;
    vector<vector<int>> levelOrder(Node* root) {
        BFS(root);
        return ans;
    }

    void BFS(Node* root)
    {
        que.push(root);
        while(!que.empty())
        {
            vector<int> v;
            int s = que.size();

            while(s--)
            {
                Node* curr = que.front();
                v.push_back(curr->val);
                que.pop();

                for(int i=0; i<curr->children.size(); i++)
                    que.push(curr->children[i]);
            }
            ans.push_back(v);
        }
    }
};