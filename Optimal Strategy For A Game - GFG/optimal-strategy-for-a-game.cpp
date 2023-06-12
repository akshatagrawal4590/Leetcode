//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long maximumAmount(int arr[], int n)
    {
        vector<vector<long long>> dp(n, vector<long long> (n, -1));
        int i = 0;
        int k = 0;
        while(k < n)
        {
            int j = k;
            while(j < n)
            {
                if(i == j)
                {
                    dp[i][j] = arr[i];
                }
                else if(j - i == 1)
                {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else
                {
                    dp[i][j] = max((arr[j] + min(dp[i+1][j-1], dp[i][j-2])), (arr[i] + min(dp[i+1][j-1], dp[i+2][j])));
                }
                i++;
                j++;
            }
            k++;
            i = 0;
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][n-1];
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
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends