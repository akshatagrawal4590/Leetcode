class Solution {
public:
    int f(vector<int> &nums, vector<vector<int>> &dp, int n, int i, int j)
    {
        if(i == n)
        {
            return 0;
        }
        if(dp[i][j+1] != -1)
        {
            return dp[i][j+1];
        }
        int x = f(nums, dp, n, i + 1, j);
        int y = 0;
        if(j == -1 || nums[i] > nums[j])
        {
            y = 1 + f(nums, dp, n, i + 1, i);
        }
        dp[i][j+1] = max(x, y);
        return dp[i][j+1];
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 2, -1));
        return f(nums, dp, n, 0, -1);
    }
};