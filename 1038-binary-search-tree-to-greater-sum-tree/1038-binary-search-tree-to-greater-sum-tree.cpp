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
    void f(vector<pair<int, TreeNode*>> &v, TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        f(v, root -> left);
        v.push_back({root -> val, root});
        f(v, root -> right);
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<pair<int, TreeNode*>> v;
        f(v, root);
        int n = v.size();
        for(int i = n - 2; i >= 0; i--)
        {
            v[i].first = v[i].first + v[i+1].first;
            v[i].second -> val = v[i].first;
        }
        return root;
    }
};