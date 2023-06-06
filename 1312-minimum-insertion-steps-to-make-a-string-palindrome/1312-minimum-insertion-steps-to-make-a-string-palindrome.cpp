class Solution {
public:
    int f(string &s1, string &s2, int ind1, int ind2, int n, int m, vector<vector<int>> &dp)
    {
        if(ind1 >= n || ind2 >= m)
            return 0;
        if(s1[ind1] == s2[ind2])
            return 1 + f(s1, s2, ind1 + 1, ind2 + 1, n, m, dp);
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int x = f(s1, s2, ind1, ind2 + 1, n, m, dp);
        int y = f(s1, s2, ind1 + 1, ind2, n, m, dp);
        dp[ind1][ind2] = max(x, y);
        return dp[ind1][ind2];
    }
    
    int minInsertions(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int x = f(s1, s2, 0, 0, n, n, dp);
        return n - x;
    }
};