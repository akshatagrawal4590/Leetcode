class Solution {
public:
    int mod = 1e9+7;
    //Strings less than or equal to s that has digit sum between max_sum and min_sum
    long long cal(int i, bool strict, int sum, string&s,int n,int min_sum, int max_sum,
    vector<vector<vector<int>>>&dp)
    {
        if(i==n)
            return sum>=min_sum && sum<=max_sum;
        if(dp[i][strict][sum]!=-1)
            return dp[i][strict][sum];
        char end = (strict)? s[i] : '9';
        long long ans = 0;
        for(char c='0';c<=end;c++)
        {
            int newSum = sum+(c-'0');
            if(newSum > max_sum)
                break;
            ans = ( ans + cal(i+1,strict & c==end,newSum,s,n,min_sum,max_sum,dp)%mod)%mod;
        }    
        return dp[i][strict][sum] = ans%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num1.size(),m = num2.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(max_sum+1,-1)));
        int p = n-1;

        //Getting num1 -1 as a string 
        while(num1[p]=='0') p--; 
        num1[p++]--;
        while(p<n) num1[p++] = '9';
        long long less = cal(0,1,0,num1,n,min_sum,max_sum,dp);
        dp.clear();
        dp.resize(m,vector<vector<int>>(2,vector<int>(max_sum+1,-1)));
      
        long long tot = cal(0,1,0,num2,m,min_sum,max_sum,dp);
        return (tot - less + mod)%mod;
    }
};