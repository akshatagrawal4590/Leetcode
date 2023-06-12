class Solution {
public:
    int f(vector<vector<int>> &v, vector<vector<int>> &dp, int n, int i, int prev)
    {
        if(i == n)
        {
            return 0;
        }
        if(dp[i][prev+1] != -1)
        {
            return dp[i][prev+1];
        }
        int x = f(v, dp, n, i + 1, prev);
        int y = 0;
        if(prev == -1 || v[i][1] == v[prev][1] || v[i][0] >= v[prev][0])
        {
            y = v[i][0] + f(v, dp, n, i + 1, i);
        }
        dp[i][prev+1] = max(x, y);
        return dp[i][prev+1];
    }
    
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[1] != b[1])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n = scores.size();
        vector<vector<int>> v;
        for(int i = 0; i < n ; i++)
        {
            vector<int> v1;
            v1.push_back(scores[i]);
            v1.push_back(ages[i]);
            v.push_back(v1);
        }
        sort(v.begin(), v.end(), compare);
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return f(v, dp, n, 0, -1);
    }
};