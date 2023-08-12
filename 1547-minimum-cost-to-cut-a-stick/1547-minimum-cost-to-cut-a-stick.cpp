class Solution {
public:
    
    int f(vector<int> &cuts, vector<vector<int>> &dp, int i, int j, int a, int b)
    {
        if(a > b)
        {
            return 0;
        }
        if(dp[a][b] != -1)
        {
            return dp[a][b];
        }
        int ans = INT_MAX;
        for(int k = a; k <= b; k++)
        {
            int x = j - i + f(cuts, dp, i, cuts[k], a, k - 1) + f(cuts, dp, cuts[k], j, k + 1, b);
            ans = min(ans, x);
        }
        dp[a][b] = ans;
        return dp[a][b];
    }
    
    int minCost(int n, vector<int>& cuts) 
    {
        int l = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(l + 1, vector<int> (l + 1, -1));
        return f(cuts, dp, 0, n, 0, l - 1);        
    }
};