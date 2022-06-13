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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue <TreeNode*> q;
        q.push(root);
        
        int prev = 1;
        int count = 0;
        
        int last = 0;   //if(last == 1) reverse; else as_it_is
        
        while(!q.empty())
        {
            vector <int> v;
            
            for(int i=0; i<prev; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(!node) break;
                v.push_back(node->val);
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
            }
            
            prev = count;
            count = 0;
            
            if(last == 0)
            {
                last = 1;
                if(v.size()) ans.push_back(v);
            }
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                last = 0;
        }
    }
        return ans;
    }
};