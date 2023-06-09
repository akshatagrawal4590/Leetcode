//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
    // long long int  countPS(string s)
    // {
    //     int n = s.length();
    //     vector<vector<int>> dp(n, vector<int> (n, 0));
    //     int i = 0;
    //     int j = 0;
    //     while(j < n)
    //     {
    //         int k = j;
    //         while(k < n)
    //         {
    //             if(i == k)
    //             {
    //                 dp[i][k] = 1;
    //             }
    //             else
    //             {
    //                 int x = k - 1;
    //                 int y = i + 1;
    //                 if(s[i] == s[k])
    //                 {
    //                     dp[i][k] = ((dp[i][x] + dp[y][k]) % 1000000007 + 1) % 1000000007;
    //                 }
    //                 else
    //                 {
    //                     dp[i][k] = ((dp[i][x] + dp[y][k]) % 1000000007 - dp[y][x]) % 1000000007; 
    //                 }
    //             }
    //             i++;
    //             k++;
    //         }
    //         j++;
    //         i = 0;
    //     }
    //     // for(long long i = 0; i < n; i++)
    //     // {
    //     //     for(long long j = 0; j < n; j++)
    //     //     {
    //     //         cout<<dp[i][j]<<" ";
    //     //     }
    //     //     cout<<endl;
    //     // }
    //     // cout<<endl;
    //     return dp[0][n-1];
    // }
    
    long long int  countPS(string str)

    {

       long long int mod=1e9+7;

       int n=str.size();

       vector<vector<long long int>> dp(n,vector<long long int>(n));

       for(int k=0;k<n;k++){

          for(int i=0,j=k+i;i<n and j<n;i++,j++){

              if(i==j) dp[i][j]=1;

              else if(j==i+1){

                  if(str[i]==str[j]) dp[i][j]=((dp[i+1][j])%mod+(dp[i][j-1])%mod+1)%mod;

                  else dp[i][j]=((dp[i+1][j])%mod+(dp[i][j-1])%mod+mod)%mod;

              }

              else{

                  if(str[i]==str[j]) dp[i][j]=((dp[i+1][j])%mod+(dp[i][j-1])%mod+1)%mod;

                  else dp[i][j]=((dp[i+1][j])%mod+(dp[i][j-1])%mod-(dp[i+1][j-1])%mod+mod)%mod;

              }

          }

       }

       return (dp[0][n-1])%mod;

    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends