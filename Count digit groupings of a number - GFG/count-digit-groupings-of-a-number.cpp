//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(vector<vector<int>> &dp, string &s, int n, int ind, int sum)
	{
	    if(ind == n)
	    {
	        return 1;
	    }
	    if(dp[ind][sum] != -1)
	    {
	        return dp[ind][sum];
	    }
	    int ans = 0;
	    int x = 0;
	    for(int i = ind; i < n; i++)
	    {
	        x = x + (s[i] - '0');
	        int y = 0;
	        if(x >= sum)
	        {
	            y = f(dp, s, n, i + 1, x);
	            ans = ans + y;
	        }
	    }
	    dp[ind][sum] = ans;
	    return dp[ind][sum];
	}
	
	int TotalCount(string str)
	{
	    int n = str.length();
	    vector<vector<int>> dp(n, vector<int> (n * 9 + 1, -1));
	    return f(dp, str, n, 0, 0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends