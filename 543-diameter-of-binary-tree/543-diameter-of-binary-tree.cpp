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
    
    int m = INT_MIN;
    
    int height(TreeNode* node)
    {
        if(!node) return 0;
        int a = 0;
        if(node->left) a = height(node->left);
        int b = 0;
        if(node->right) b = height(node->right);

        m = max(m, a+b);

        return 1+max(a, b);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        m = INT_MIN;
        height(root);
        
        return m;
    }
};