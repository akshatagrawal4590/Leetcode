// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         int dp[k+1][n+1];
//         for(int i = 0; i <= n; i++) dp[0][i] = INT_MAX;
//         for(int i = 0; i <= n; i++) dp[1][i] = i;
//         for(int i = 0; i <= k; i++) dp[i][0] = 0;
//         for(int i = 0; i <= k; i++) dp[i][1] = 1;
        
//         for(int i = 2; i <= k; i++)
//             for(int j = 2; j <= n; j++){
//                 int curr_ans = INT_MAX;
//                 int l = 0, r = j-1;
//                 while(l < j && r >= 0){
//                     curr_ans = min(curr_ans, max(dp[i-1][l], dp[i][r]));
//                     l++; r--;
//                 }
//               dp[i][j] = curr_ans+1;
//             }
//         return dp[k][n];
//     }
// };
class Solution {
public:
    //Time: O(n*k*logn), Space: O(n*k)
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            
            int left = helper(k-1, mid-1, memo);
            int right = helper(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     //move to the downward
    
            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        //k means number of eggs, n means number of floors
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }
};