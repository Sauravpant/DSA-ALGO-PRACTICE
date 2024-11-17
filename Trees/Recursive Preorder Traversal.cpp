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
class Solution
 {
     vector<int> v;
   void preorderBST(TreeNode* root)
     {
        if(root==nullptr)
        return;
        v.push_back(root->val);
        preorderBST(root->left);
        preorderBST(root->right);
     }
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        preorderBST(root);
        return v;
    }
};