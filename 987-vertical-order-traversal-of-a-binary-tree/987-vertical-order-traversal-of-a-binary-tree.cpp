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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        queue <pair<TreeNode*, pair<int, int>>> q;  // {node, vert, level}

        map <int, map<int, multiset<int>>> m;   //to store the answer

        q.push({root, {0,0}});
        while(!q.empty())
        {
            auto temp = q.front();
            TreeNode* node = temp.first;
            q.pop();

            int vert = temp.second.first;
            int level = temp.second.second;

            m[vert][level].insert(node->val);

            if(node->left)
            {
                q.push({node->left, {vert-1 , level+1}});
            }
            if(node->right)
            {
                q.push({node->right, {vert+1 , level+1}});
            }
        }
        
        vector<vector<int>> v;

        for(auto p : m)
        {
            vector <int> verti;
            for(auto q : p.second)
            {
                // multiset <int> :: iterator i;
                // for(i=q.second.begin(); i!=q.second.end(); i++)
                // {
                //     verti.push_back(*i);
                // }

                for(auto r : q.second)
                {
                    verti.push_back(r);
                }
            }
            v.push_back(verti);
        }

        return v;


        
    }
};
