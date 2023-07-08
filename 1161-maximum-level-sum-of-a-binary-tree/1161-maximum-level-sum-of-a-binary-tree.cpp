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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MAX;
        int level = 1;
        int count = INT_MIN;
        while(q.size() != 0)
        {
            int n = q.size();
            int x = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                x = x + temp -> val;
                if(temp -> left != NULL)
                {
                    q.push(temp -> left);
                }
                if(temp -> right != NULL)
                {
                    q.push(temp -> right);
                }
            }
            if(x > count)
            {
                count = x;
                ans = level;
            }
            else if(x == count)
            {
                ans = min(ans, level);
            }
            level++;
        }
        return ans;
    }
};