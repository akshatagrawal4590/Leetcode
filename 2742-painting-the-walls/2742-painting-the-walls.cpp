class Solution {
public:
    
//     int fn(vector<int>& cost, vector<int>& time, vector<vector<vector<long long>>> &dp, int n, int i, long long f, long long c)
//     {
//         if(i == n)
//         {
//             if(f <= c)
//             {
//                 return 0;
//             }
//             else
//             {
//                 return 1e8;
//             }
//         }
//         if(dp[i][f][c] != -1)
//         {
//             return dp[i][f][c];
//         }
//         long long pc = cost[i] + fn(cost, time, dp, n, i + 1, f, c + time[i]);
//         long long fc = fn(cost, time, dp, n, i + 1, f + 1, c);
//         dp[i][f][c] = min(pc, fc);
//         return dp[i][f][c];
        
//     }
    
//     int paintWalls(vector<int>& cost, vector<int>& time) 
//     {
//         int n = cost.size();
//         long long x = 0;
//         for(int i = 0; i < n; i++)
//         {
//             x = x + time[i];
//         }
//         vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n + 1, vector<long long>(x + 1, -1)));
//         return fn(cost, time, dp, n, 0, 0, 0);
//     }
    int dp[501][501] = {};

int solve(vector<int>& cost, vector<int>& time, int i, int wallReamining){
    if(wallReamining <= 0) return 0;
    if(i >= cost.size()) return 1000000000;
    if(dp[i][wallReamining] != 0) return dp[i][wallReamining];
    int notTake = solve(cost, time, i+1, wallReamining);
    int take = cost[i] + solve(cost, time, i+1, wallReamining -  time[i] -1); 
    return dp[i][wallReamining] = min(notTake, take);      
}

int paintWalls(vector<int>& cost, vector<int>& time) {
    return solve(cost, time, 0, time.size());
}
};