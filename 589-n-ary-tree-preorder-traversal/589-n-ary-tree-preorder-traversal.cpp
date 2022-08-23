/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(vector<int> &ans, Node* root)
    {
        if(root == NULL)
            return;
        int n = root -> children.size();
        ans.push_back(root -> val);
        for(int i = 0; i < n; i++)
            f(ans, root -> children[i]);
    }
    
    vector<int> preorder(Node* root) 
    {
        vector<int> ans;
        f(ans, root);
        return ans;
    }
};