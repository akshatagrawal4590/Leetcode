//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    long long f(vector<long long> &dp, int n)
    {
        if(n == 0)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        long long x = 0;
        long long y = 0;
        long long z = 0;
        if(n - 1 >= 0)
        {
            x = f(dp, n - 1);
        }
        if(n - 2 >= 0)
        {
            y = f(dp, n - 2);
        }
        if(n - 3 >= 0)
        {
            z = f(dp, n - 3);
        }
        dp[n] = (x + y + z) % 1000000007;
        return dp[n];
    }
    
    long long countWays(int n)
    {
        vector<long long> dp(n + 1, -1);
        return f(dp, n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends