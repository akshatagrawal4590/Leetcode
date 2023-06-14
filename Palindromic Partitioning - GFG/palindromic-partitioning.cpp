//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(vector<vector<int>> &dp, vector<vector<int>> &pal, string &s, int i, int j)
    {
        if(pal[i][j] == 1)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i + 1; k <= j; k++)
        {
            if(pal[i][k-1] == 1)
            {
                int x = 1 + f(dp, pal, s, k, j);    
                ans = min(ans, x);
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>> pal(n, vector<int> (n, 0));
        int k = 0;
        while(k < n)
        {
            int i = 0;
            int j = k;
            while(j < n)
            {
                if(i == j)
                {
                    pal[i][j] = 1;
                }
                else if(j - i == 1)
                {
                    if(str[i] == str[j])
                    {
                        pal[i][j] = 1;
                    }
                }
                else
                {
                    if(str[i] == str[j])
                    {
                        int x = i + 1;
                        int y = j - 1;
                        if(pal[x][y] == 1)
                        {
                            pal[i][j] = 1;
                        }
                    }
                }
                i++;
                j++;
            }
            k++;
        }
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(dp, pal, str, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends