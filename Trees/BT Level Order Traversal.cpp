/*
102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: [
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> v;
        if(root==nullptr)
        return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
          vector<int> level;
          int size=q.size();
          for(int i=0;i<size;i++)
          {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=nullptr)
            q.push(temp->left);
            if(temp->right!=nullptr)
            q.push(temp->right);
            level.push_back(temp->val);
          }
          v.push_back(level);
        }
        return v;
    }
};