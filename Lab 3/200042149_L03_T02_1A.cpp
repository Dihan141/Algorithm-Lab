#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        DFS(root);
        return sum;
    }

    void DFS(TreeNode* root){
        if(root == nullptr) 
            return;

        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            sum += root->left->val;

        DFS(root->left);
        DFS(root->right);
    }   
};