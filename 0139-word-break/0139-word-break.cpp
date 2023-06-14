class Solution {
public:
    int f(vector<vector<int>> &dp, unordered_map<string, int> &m, string &s, int n, int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        if(j == n)
        {
            if(m.count(s.substr(i, j - i)) > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int x = 0;
        if(m.count(s.substr(i, j - i + 1)) > 0)
        {
            x = f(dp, m, s, n, j + 1, j + 1);
        }
        int y = f(dp, m, s, n, i, j + 1);
        dp[i][j] = x | y;
        return dp[i][j];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string, int> m;
        int n = wordDict.size();
        for(int i = 0; i < n; i++)
        {
            m[wordDict[i]] = 1;
        }
        int l = s.length();
        vector<vector<int>> dp(l + 1, vector<int> (l + 1, -1));
        return f(dp, m, s, l, 0, 0);
    }
};