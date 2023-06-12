class Solution {
public:
    bool PredictTheWinner(vector<int>& arr) 
    {
        int n = arr.size();
        int sum = 0;
        vector<vector<long long>> dp(n, vector<long long> (n, -1));
        int i = 0;
        int k = 0;
        while(k < n)
        {
            int j = k;
            while(j < n)
            {
                if(i == j)
                {
                    dp[i][j] = arr[i];
                    sum = sum + arr[i];
                }
                else if(j - i == 1)
                {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else
                {
                    dp[i][j] = max((arr[j] + min(dp[i+1][j-1], dp[i][j-2])), (arr[i] + min(dp[i+1][j-1], dp[i+2][j])));
                }
                i++;
                j++;
            }
            k++;
            i = 0;
        }
        int x = sum - dp[0][n-1];
        if(x > dp[0][n-1])
        {
            return false;
        }
        return true;
    }
};