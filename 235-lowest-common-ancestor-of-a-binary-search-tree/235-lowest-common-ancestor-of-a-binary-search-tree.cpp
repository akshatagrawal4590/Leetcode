/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findparent(TreeNode* root, TreeNode* node, vector<TreeNode*> &v)
    {
        if(root -> val == node -> val)
        {
            v.push_back(root);
            return;
        }
        else if(root -> val > node -> val)
        {
            findparent(root -> left, node, v);
            v.push_back(root);
            return;
        }
        else
        {
            findparent(root -> right, node, v);
            v.push_back(root);
            return;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> p1;
        vector<TreeNode*> q1;
        findparent(root, p, p1);
        findparent(root, q, q1);
        int psize = p1.size();
        int qsize = q1.size();
        int i = 0;
        int j = 0;
        while(1)
        {
            if(psize > qsize)
            {
                i++;
                psize--;
            }
            else if(psize < qsize)
            {
                j++;
                qsize--;
            }
            else
            {
                if(p1[i] == q1[j])
                    return p1[i];
                else
                {
                    i++;
                    j++;
                }
            }
        }
        return root;
    }
};