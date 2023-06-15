//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution
{
  public:
    // int f(int a[], vector<vector<long long>> &dp, long long n, int i, int j)
    // {
    //     if(i == n)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }
    //     int x = a[i] + f(a, dp, n, i + 1, 0);
    //     int y = INT_MAX;
    //     if(j == 0)
    //     {
    //         y = f(a, dp, n, i + 1, 1);
    //     }
    //     dp[i][j] = min(x, y);
    //     return dp[i][j];
    // }
  
    int minAmount(int nums[] , int n)
    {
        //code here.
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        for(int i = n-1; i>=0; i--){
            for(int flag = 0; flag<= 1; flag++){
              if(flag){
             dp[i][flag]=min(dp[i+1][1]+nums[i],dp[i+1][0]);
        }else{
                dp[i][flag]=dp[i+1][1]+nums[i];
        }
        
            }
        }
        return dp[0][1];
       // return f(N-1 , 1 ,A, dp );
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
            int arr[n];
            for(int i = 0;i<n;i++)
                cin>>arr[i];
            Solution ob;    
            cout<<ob.minAmount(arr,n)<<endl;    
        }
}
// } Driver Code Ends