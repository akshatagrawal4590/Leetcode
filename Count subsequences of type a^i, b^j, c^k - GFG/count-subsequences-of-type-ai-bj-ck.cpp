//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    
    // int f(string &s, vector<int> &dp, int n, int i, int a, int b, int c)
    // {
    //     if(i == n)
    //     {
    //         if(a > 0 && b > 0 && c > 0)
    //         {
    //             return 1;
    //         }
    //         else
    //         {
    //             return 0;
    //         }
    //     }
    //     if(dp[i][a][b][c] != -1)
    //     {
    //         return dp[i][a][b][c];
    //     }
    //     int x = f(s, dp, n, i + 1, a, b, c) % 1000000007;
    //     int y = 0;
    //     if(a == 1)
    //     {
    //         if(s[i] == 'a')
    //         {
    //             y = f(s, dp, n, i + 1, a, b, c) % 1000000007;
    //         }
    //     }
        
    //     else if(s[i] == 'b')
    //     {
    //         y = f(s, dp, n, i + 1, a, b + 1, c) % 1000000007;
    //     }
    //     else
    //     {
    //         y = f(s, dp, n, i + 1, a, b, c + 1) % 1000000007;
    //     }
    //     dp[i][a][b][c] = (x + y) % 1000000007;
    //     return dp[i][a][b][c];
    // }
    
    int fun(string &s) 
    {
        int n = s.length();
        long a = 0;
        long b = 0;
        long c = 0;
        int i = 0;
        while(i < n)
        {
            if(s[i] == 'a')
            {
                a = ((a * 2) + 1) % 1000000007;
            }
            else if(s[i] == 'b')
            {
                b = (a + b + b) % 1000000007;
            }
            else
            {
                c = (b + c + c) % 1000000007;
            }
            i++;
        }
        return (int)c;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends