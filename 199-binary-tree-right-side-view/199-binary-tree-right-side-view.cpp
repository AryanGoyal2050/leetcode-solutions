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
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode*> q;

        vector<int> ans;
        TreeNode* node = root;

        q.push(root);

        int prev = 1;
        int count = 0;

        while(!q.empty())
        {
            if(!q.front()) break;
            
            for(int i=0; i<prev; i++)
            {
                node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    count++;
                }
                if(node->right)
                {
                    q.push(node->right);
                    count++;
                }
                if(i == prev-1) ans.push_back(node->val);
            }

            prev = count;
            count = 0;
        }

        return ans;




    }
};