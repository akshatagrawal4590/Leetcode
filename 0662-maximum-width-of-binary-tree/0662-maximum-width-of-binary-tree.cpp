class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if(root==NULL)
    {
        return 0;
    }
    queue<pair<TreeNode*,long long int>> q;
    q.push({root, 0});
    long long ans=0;
    while(!q.empty())
    {
        int sz=q.size();
        long long int first;
        long long int last;
        int min_n=q.front().second;
        for(int i=0;i<sz;i++)
        {
            auto it=q.front();
            q.pop();
            TreeNode *node=it.first;
            long long int curr=it.second - min_n;
            if(i==0)
            {
                first=curr;
            }
            if(i==sz-1)
            {
                last=curr;
            }
            if(node->left!=NULL)
            {
                q.push({node->left,curr*2+1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,curr*2+2});
            }
        }
        //cout<<first<<" "<<last<<endl;
        ans=max(ans,last-first+1);
    }
    return ans;
    }
};