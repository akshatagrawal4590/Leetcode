//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int arr[], vector<vector<int>> &dp, int n, int i, int prev)
	{
	    if(i == n)
	    {
	        return 0;
	    }
	    if(dp[i][prev+1] != -1)
	    {
	        return dp[i][prev+1];
	    }
	    int x = f(arr, dp, n, i + 1, prev);
	    int y = 0;
	    if((prev == -1) || (arr[i] > arr[prev]))
	    {
	        y = arr[i] + f(arr, dp, n, i + 1, i);
	    }
	    dp[i][prev+1] = max(x, y);
	    return dp[i][prev+1];
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	    return f(arr, dp, n, 0, -1);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends