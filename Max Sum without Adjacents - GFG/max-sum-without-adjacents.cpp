//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int f(vector<int> &arr, vector<vector<int>> &dp, int n, int i, int prev)
// 	{
// 	    if(i == n)
// 	    {
// 	        return 0;
// 	    }
// 	    if(dp[i][prev+1] != -1)
// 	    {
// 	        return dp[i][prev+1];
// 	    }
// 	    int x = f(arr, dp, n, i + 1, prev);
// 	    int y = 0;
// 	    if(prev == -1 || prev + 1 != i)
// 	    {
// 	        y = arr[i] + f(arr, dp, n, i + 1, i);
// 	    }
// 	    dp[i][prev+1] = max(x, y);
// 	    return dp[i][prev+1];
// 	}
	
	int findMaxSum(vector<int>&arr, int n) 
	{
	    //vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	    //return f(arr, dp, n, 0, -1);
	    vector<int>dp(n+1,-1);
       dp[n-1]=arr[n-1];
       dp[n]=0;
       for(int i=n-2;i>=0;i--)
       {
           dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
       }
       return dp[0];
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends