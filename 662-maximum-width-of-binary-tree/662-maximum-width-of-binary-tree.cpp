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

typedef long long ll;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;
        
        queue <pair <TreeNode*, long>> q;    // {node, verti}
        int ans = INT_MIN;  //maximum width

        q.push({root, 0});
        int prev = 1;
        int count = 0;

        int max_width = INT_MIN;

        while(!q.empty())
        {
            int curr_width = 0;
            int m1, m2;

            auto temp = q.front();
            int base = temp.second;
            cout<<"base = "<<base<<endl;

            for(int i=0; i<prev; i++)
            {
                auto ob = q.front();
                TreeNode* node = ob.first;
                q.pop();

                cout<<ob.second-base<<" ";

                if(i == 0) m1 = ob.second-base;
                if(i == prev - 1) m2 = ob.second-base;

                if(node->left)
                {
                    count++;
                    q.push({node->left, 2*(ob.second-base)+1});
                }
                if(node->right)
                {
                    count++;
                    q.push({node->right, 2*(ob.second-base)+2});
                }
            }
            cout<<endl;

            prev = count;
            count = 0;

            cout<<"m1 = "<<m1<<" m2 = "<<m2<<endl;

            curr_width = (m2-m1)+1;

            max_width = max(max_width, curr_width);
        }

        return max_width;
    }
};