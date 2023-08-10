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
    
    pair<int, int> f(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0, 0};
        }
        pair<int, int> p1 = f(root -> right);
        pair<int, int> p2 = f(root -> left);
        int x = max(p1.second + p2.second, max(p2.first, p1.first));
        int y = max(p1.second, p2.second) + 1;
        return {x, y};
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return f(root).first;
    }
};