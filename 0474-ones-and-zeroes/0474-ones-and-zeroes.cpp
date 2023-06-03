// class Solution {
// public:
//     int f(vector<string> &str, vector<vector<vector<int>>> &dp, int m, int n, int l, int i, int j, int k)
//     {
//         if(i == l)
//         {
//             return 0;
//         }
//         if(dp[i][j][k] != -1)
//         {
//             return dp[i][j][k];
//         }
//         int z = stoi(str[i]);
//         int y = z % 10;
//         z =  z / 10;
//         int x = z % 10;
//         int a = f(str, dp, m, n, l, i + 1, j, k);
//         int b = 0;
//         if(j + x <= m && k + y <= n)
//         {
//             b = 1 + f(str, dp, m, n, l, i + 1, j + x, k + y);
//         }
//         dp[i][j][k] = max(a, b);
//         return dp[i][j][k];
//     }
    
//     int findMaxForm(vector<string>& str, int m, int n) 
//     {
//         int l = str.size();
//         for(int i = 0; i < l; i++)
//         {
//             int x = 0;
//             int y = 0;
//             int z = str[i].length();
//             for(int j = 0; j < z; j++)
//             {
//                 if(str[i][j] == '1')
//                 {
//                     y++;
//                 }
//                 else
//                 {
//                     x++;
//                 }
//             }
//             string s = "";
//             s = s + to_string(x) + to_string(y);
//             str[i] = s;
//         }
//         vector<vector<vector<int>>> dp(l, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
//         return f(str, dp, m, n, l, 0, 0, 0);
//     }
// };

class Solution {
    int dfs(int i, int s, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp) {
        if(i == s) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int notpick = dfs(i + 1, s, m, n, strs, dp);
        int cnt0 = 0, cnt1 = 0, pick = 0;
        for(char c : strs[i]) {
            c == '0' ? cnt0++ : cnt1++;
        }
        if(m >= cnt0 && n >= cnt1) {
            pick = 1 + dfs(i + 1, s, m - cnt0, n - cnt1, strs, dp);
        }
        return dp[i][m][n] = max(pick, notpick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(s, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, s, m, n, strs, dp);
    }
};