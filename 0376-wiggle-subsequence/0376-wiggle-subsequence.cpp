class Solution {
public:
    int f(vector<vector<vector<int>>> &dp, vector<int> &nums, int n, int i, int prev, int j)
    {
        if(i == n)
        {
            return 0;
        }
        if(dp[i][prev+1][j+1] != -1)
        {
            return dp[i][prev+1][j+1];
        }
        if(prev == -1)
        {
            int a = 1 + f(dp, nums, n, i + 1, i, 0);
            int b = 1 + f(dp, nums, n, i + 1, i, 1);
            int c = f(dp, nums, n, i + 1, prev, j);
            dp[i][prev+1][j+1] = max(a, max(b, c));
            return dp[i][prev+1][j+1];
        }
        else
        {
            int x = f(dp, nums, n, i + 1, prev, j);
            int y = 0;
            int z = 0;
            if(j == 0 && nums[i] < nums[prev])
            {
               y = 1 + f(dp, nums, n, i + 1, i, 1);
            }
            else if(j == 1 && nums[i] > nums[prev])
            {
                z = 1 + f(dp, nums, n, i + 1, i, 0);
            }
            dp[i][prev+1][j+1] = max(x, max(y, z));
            return dp[i][prev+1][j+1];
        }
    }
    
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n + 1, vector<int> (3, -1)));
        return f(dp, nums, n, 0, -1, -1);    
    }
};