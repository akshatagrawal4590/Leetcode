//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    // int f(int arr[], vector<vector<int>> &dp, int n, int i, int k)
    // {
    //     if(i >= n)
    //     {
    //         return 0;
    //     }
    //     if(k >= n - 4 && k <= n - 1)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][k] != -1)
    //     {
    //         return dp[i][k];
    //     }
    //     if(k >= i && k <= i + 3)
    //     {
    //         return f(arr, dp, n, i + 1, k);
    //     }
    //     int a = INT_MAX;
    //     for(int j = 0; j < 4; j++)
    //     {
    //         int x = i + j;
    //         int y = INT_MAX;
    //         if(x < n)
    //         {
    //             y = arr[x] + f(arr, dp, n, i + 1, x);
    //             a = min(a, y);
    //         }
    //     }
    //     dp[i][k] = a;
    //     return dp[i][k];
    // }
    
    // int minSum(int arr[], int n)
    // {
    //     if(n <= 3)
    //     {
    //         int x = INT_MAX;
    //         for(int i = 0; i < n; i++)
    //         {
    //             x = min(x, arr[i]);
    //         }
    //         return x;
    //     }
    //     vector<vector<int>> dp(n, vector<int> (n, -1));
    //     return f(arr, dp, n, 0, -1);
    // }
    
    int minSum(int arr[], int n){
        
        if(n<=4){
            int mini=arr[0];
            for(int i=1;i<n;i++) mini = min(mini,arr[i]);
            return mini;
        }
        
        vector<int>dp(n,0);
        for(int i=0;i<4;i++) dp[i] = arr[i];
        
        for(int i=4;i<n;i++)
            dp[i] = arr[i] + min(dp[i-1],min(dp[i-2],min(dp[i-3],dp[i-4])));
        
        return min(dp[n-1],min(dp[n-2],min(dp[n-3],dp[n-4])));
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends