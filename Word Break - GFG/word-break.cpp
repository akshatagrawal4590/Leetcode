//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int f(string &s, unordered_map<string, int> &m, vector<vector<int>> &dp, int i, int j, int n)
    {
        if(i == n && j == n)
        {
            return 1;
        }
        if(j == n)
        {
            if(m.count(s.substr(i, j - i)) > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int x = f(s, m, dp, i, j + 1, n);
        int y = 0;
        if(m.count(s.substr(i, j - i + 1)) > 0)
        {
            y = f(s, m, dp, j + 1, j + 1, n);
        }
        dp[i][j] = x || y;
        return dp[i][j];
    }

    int wordBreak(string a, vector<string> &b) 
    {
        unordered_map<string, int> m;
        for(int i = 0; i < b.size(); i++)
        {
            if(m.count(b[i]) == 0)
            {
                m[b[i]] = 1;
            }
        }
        int n = a.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(a, m, dp, 0, 0, n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends