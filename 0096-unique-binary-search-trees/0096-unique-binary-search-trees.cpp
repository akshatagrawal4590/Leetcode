class Solution {
public:
    int f(vector<long long> &dp, int i)
    {
        if(i == 0)
        {
            return 1;
        }
        if(i == 1 || i == 2)
        {
            return i;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        long long x = 0;
        for(int j = 1; j <= i; j++)
        {
            long long a = f(dp, j - 1);
            long long b = f(dp, i - j);
            x = x + (a * b);
        }
        dp[i] = x;
        return dp[i];
    }
    
    int numTrees(int n) 
    {
        vector<long long> dp(n + 1, -1);
        return f(dp, n);
    }
};