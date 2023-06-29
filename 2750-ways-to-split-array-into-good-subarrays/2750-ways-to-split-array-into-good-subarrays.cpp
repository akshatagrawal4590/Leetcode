class Solution {
public:
//     int mod = 1000000007;
    
//     int f(vector<int> &nums, vector<vector<vector<int>>> &dp, int i, int j, int sum, int n)
//     {
//         // if(j == n)
//         // {
//         //     if(i == n)
//         //     {
//         //         return 0;
//         //     }
//         //     else
//         //     {
//         //         return 1;
//         //     }
//         // }
//         if(dp[i][j][sum] != -1)
//         {
//             return dp[i][j][sum];
//         }
//         int count = 0;
//         while(sum < 2 && j < n)
//         {
//             if(sum == 0)
//             {
//                 sum = sum + nums[j];
//             }
//             else
//             {
//                 count = (count + f(nums, dp, j, j, 0, n)) % mod;
//                 sum = sum + nums[j];
//             }
//             j++;
//         }
//         if(sum == 1)
//         {
//             count++;
//         }
//         dp[i][j][sum] = count;
//         return dp[i][j][sum];
//     }
    
//     int numberOfGoodSubarraySplits(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (3, -1)));
//         return f(nums, dp, 0, 0, 0, n);
//     }
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
    long long ans = 1, m = 1000000007, count  = 0;
    int i = 0;
    while(i < nums.size() && nums[i] == 0) ++i;
    if(i >= nums.size() ) return 0;
    while(i < nums.size()){
        if(nums[i] == 1){  ans = (ans * (count +1 ))%m;  count = 0; }
        else count++;
        i++;
    }
    return ans;
}
};