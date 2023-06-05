class Solution {
public:
    int f(string &s1, string &s2, string &s3, vector<vector<int>> &dp, int i, int j, int k, int l1, int l2, int l3)
    {
        if(i == l1 && j == l2 && k == l3)
        {
            return 1;
        }
        // else 
        // {
        //     if((k != l3 && i == l1) || (k != l3 && j == l2))
        //     return 0;
        // }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int x = 0;
        int y = 0;
        if(s3[k] == s1[i])
        {
            x = f(s1, s2, s3, dp, i + 1, j, k + 1, l1, l2, l3);
        }
        if(s3[k] == s2[j])
        {
            y = f(s1, s2, s3, dp, i, j + 1, k + 1, l1, l2, l3);
        }
        dp[i][j] = x | y;
        return dp[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if(l1 + l2 > l3)
        {
            return false;
        }
        vector<vector<int>> dp(l1 + 1, vector<int> (l2 + 1, -1));
        return f(s1, s2, s3, dp, 0, 0, 0, l1, l2, l3);
    }
};