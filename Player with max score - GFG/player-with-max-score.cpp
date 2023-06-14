//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool is1winner(int n,int arr[]) 
    {
        int sum = 0;
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
                    sum = sum + arr[i];
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
        int x = sum - dp[0][n-1];
        if(x >= dp[0][n-1])
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends