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
    
    pair<bool, int> f(TreeNode* root)
    {
        if(root == NULL)
        {
            return {true, 0};
        }
        pair<bool, int> p1 = f(root -> left);
        pair<bool, int> p2 = f(root -> right);
        if(p1.first == false || p2.first == false || abs(p1.second - p2.second) > 1)
        {
            return {false, 0};
        }
        return {true, max(p1.second, p2.second) + 1};
        
    }
    
    bool isBalanced(TreeNode* root) 
    {
        return f(root).first;
    }
};