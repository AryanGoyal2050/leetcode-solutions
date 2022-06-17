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
    int check = 1;
    int height(TreeNode* node)
    {
        if(!node) return 0;
        int l = 0;
        int r = 0;
        if(node->left) l = height(node->left);
        if(node->right) r = height(node->right);
        if(abs(r-l) > 1) check = 0;
        return 1+max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        height(root);
        return (bool)check;
    }
};