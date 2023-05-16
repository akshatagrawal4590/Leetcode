class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        ans.push_back(0);
        int i = 1;
        while(i <= n)
        {
            if(i == 1)
            {
                ans.push_back(1);
                i++;
                continue;
            }
            else if(i % 2 == 0)
            {
                ans.push_back(ans[i/2]);
                i++;
            }
            else
            {
                int x = ans[i/2] + 1;
                ans.push_back(x);
                i++;
            }
        }
        return ans;
    }
};