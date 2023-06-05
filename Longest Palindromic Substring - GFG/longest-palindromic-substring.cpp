//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int i = 0;
        int j = 0;
        while(j < n)
        {
            int k = j;
            while(k < n)
            {
                if(s[i] == s[k])
                {
                    if(i == k)
                    {
                        dp[i][k] = 1;
                        ans = max(ans, k - i + 1);
                    }
                    else
                    {
                        int x = i + 1;
                        int y = k - 1;
                        if(x > y)
                        {
                            dp[i][k] = 1;
                            ans = max(ans, k - i + 1);
                        }
                        else
                        {
                            dp[i][k] = dp[x][y];
                            if(dp[x][y] == 1)
                            {
                                ans = max(ans, k - i + 1);
                            }
                        }
                    }
                }
                i++;
                k++;
            }
            j++;
            i = 0;
        }
        string str = "";
        for(int i = 0; i < n; i++)
        {
            for(j = i; j < n; j++)
            {
                if(dp[i][j] == 1 && (j - i + 1 == ans))
                {
                    str = s.substr(i, ans);
                    return str;
                }
            }
        }
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends