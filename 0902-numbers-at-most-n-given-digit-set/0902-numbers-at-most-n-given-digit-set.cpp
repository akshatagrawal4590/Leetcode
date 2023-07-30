class Solution {
public:
    int f(vector<vector<int>> &dp, string s, vector<string> &digits, int n1, int len, int i, int constraint)
    {
        if(i == len)
        {
            return 1;
        }
        if(dp[i][constraint] != -1)
        {
            return dp[i][constraint];
        }
        int x = 0;
        if(constraint == 0)
        {
            return pow(n1, len - i);
        }
        else
        {
            for(int it = 0; it < n1; it++)
            {
                if(s[i] > digits[it][0])
                {
                    x = x + f(dp, s, digits, n1, len, i + 1, 0);
                }
                else if(s[i] == digits[it][0])
                {
                    x = x + f(dp, s, digits, n1, len, i + 1, 1);
                }
            }
        }
        dp[i][constraint] = x;
        return dp[i][constraint];
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) 
    {
        int len = floor(log10(n)) + 1;
        int ans = 0;
        int n1 = digits.size();
        for(int i = 1; i < len; i++)
        {
            ans = ans + pow(n1, i);
        }
        vector<vector<int>> dp(len, vector<int> (2, -1));
        return ans + f(dp, to_string(n), digits, n1, len, 0, 1);
    }
};