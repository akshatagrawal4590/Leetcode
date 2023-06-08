//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    static bool compareVal(const val &a, const val &b) 
    {
        return a.second < b.second;
    }
    
    // int f(struct val p[], vector<int> &dp, int n, int i, int k)
    // {
    //     if(i == n)
    //     {
    //         return 0;
    //     }
    //     if(dp[i] != -1)
    //     {
    //         return dp[i];
    //     }
    //     int x = 0;
    //     int y = 0;
    //     if(k < p[i].first)
    //     {
    //         x = f(p, dp, n, i + 1, k);
    //         y = 1 + f(p, dp, n, i + 1, p[i].second);
    //     }
    //     else
    //     {
    //         x = f(p, dp, n, i + 1, k);
    //     }
    //     dp[i] = max(x, y);
    //     return dp[i];
    // }

    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n)
    {
        sort(p, p + n, compareVal);
        //vector<int> dp(n, -1);
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // }
        int ans = 0;
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            if(p[i].first > k)
            {
                ans++;
                k = p[i].second;
            }
        }
        return ans;
        //return f(p, dp, n, i, 0);
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends