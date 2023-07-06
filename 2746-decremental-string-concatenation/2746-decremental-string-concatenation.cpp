class Solution {
public:
    int dp[1001][27][27];
    int helper(int ind,vector<string>& words,int n,char frst,char last){
        if(ind == n)
            return 0;
        if(dp[ind][frst - 'a'][last - 'a'] != -1)
            return dp[ind][frst - 'a'][last - 'a'];
        string curr = words[ind];
        int ans = 50001, size = curr.size();

        int curr_size1 = (last == curr[0]) ? size - 1 : size;
        int curr_size2 = (curr.back() == frst) ? size - 1 : size;

        ans = min(ans,curr_size1 + helper(ind+1,words,n,frst,curr.back()));
        ans = min(ans,curr_size2 + helper(ind+1,words,n,curr[0],last));
        
        return dp[ind][frst - 'a'][last - 'a'] = ans;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        memset(dp,-1,sizeof(dp));
        return words[0].size() + helper(1,words,n,words[0][0],words[0].back());
    }
};