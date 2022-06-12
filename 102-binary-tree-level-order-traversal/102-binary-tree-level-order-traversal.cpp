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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector <vector<int>> ans;
        
        queue <TreeNode *> q;
        int prev = 1;
        int count = 0;   //number of elements at each level
        vector <TreeNode*> v;
        q.push(root);
        while(!q.empty())
        {
            vector <int> temp;
            
            for(int i=0; i<prev; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node);
                if(node == NULL) break;
                if(node->left != NULL)
                {
                    q.push(node->left);
                    count++;
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                    count++;
                }
                temp.push_back(node->val);
            }
                   
            prev = count;
            count = 0;
            if(temp.size() > 0) ans.push_back(temp);
        }
        
        
        

        return ans;
    }
};