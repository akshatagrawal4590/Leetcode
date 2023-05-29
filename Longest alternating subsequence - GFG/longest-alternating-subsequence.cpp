//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n=nums.size();
		    vector<vector<int>> dp(n+1,vector<int>(3,0));
		    for(int ind=n-1;ind>=0;ind--)
		    {
		        
		        for(int cond=0;cond<3;cond++)
		        {
		            int points=0;
        	        if(cond==0)
        	        {
        	            points=max(0+dp[ind+1][cond+1],max(1+dp[ind+1][cond+2],1+dp[ind+1][cond+1]));
        	            
        	        }
        	        
        	        if(cond==1)
        	        {
        	            
        	           if(nums[ind]<nums[ind-1])
        	           {
        	               points=max(0+dp[ind+1][cond],1+dp[ind+1][cond+1]);
        	           }else{
        	               points=max(points,0+dp[ind+1][cond]);
        	               
        	           }
        	        }
        	        
        	        if(cond==2)
        	        {
        	           if(nums[ind]>nums[ind-1])
        	           {
        	               points=max(0+dp[ind+1][cond],1+dp[ind+1][cond-1]);
        	           }else{
        	               points=max(points,dp[ind+1][cond]);
        	               
        	           }
        	        } 
        	        dp[ind][cond]=points;
		        }
	        
		        
		    }
		    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends