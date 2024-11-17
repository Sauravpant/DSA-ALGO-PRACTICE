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
   void postorderBST(TreeNode* root)
     {
        if(root==nullptr)
        return;
        postorderBST(root->left);
        postorderBST(root->right);
        v.push_back(root->val);
     }
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        postorderBST(root);
        return v;
    }
};