class Solution {
public:
    long long f(long long n, vector<vector<long long>> &dp, vector<int> &nums, long long i, long long flag)
    {
        if(i == n)
        {
            return 0;
        }
        if(dp[i][flag] != -1)
        {
            return dp[i][flag];
        }
        long long x = f(n, dp, nums, i + 1, flag);
        long long y = 0;
        if(flag == 0)
        {
            y = nums[i] + f(n, dp, nums, i + 1, 1);
        }
        else
        {
            y = f(n, dp, nums, i + 1, 0) - nums[i];
        }
        dp[i][flag] = max(x, y);
        return dp[i][flag];
    }
    
    long long maxAlternatingSum(vector<int>& nums) 
    {
        long long n = nums.size();
        //if()
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return f(n, dp, nums, 0, 0);
    }
};