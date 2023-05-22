//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int arr[], vector<vector<int>> &dp, int n, int sum, int ind)
	{
	    if(sum == 0)
	    {
	        int ans = 1;
	        int zc = 0;
	        for(int i = ind; i < n; i++)
	        {
	            if(arr[i] == 0)
	                zc++;
	        }
	        ans = ans + pow(2, zc) - 1;
	        return ans;
	    }
	    if(sum < 0 || ind >= n)
	        return 0;
	    if(dp[ind][sum] != -1)
	        return dp[ind][sum];
	    int x = (f(arr, dp, n, sum, ind + 1)) % 1000000007;
	    int y = (f(arr, dp, n, sum - arr[ind], ind + 1)) % 1000000007;
	    dp[ind][sum] = (x + y) % 1000000007;
	    return dp[ind][sum];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        return f(arr, dp, n, sum, 0);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends