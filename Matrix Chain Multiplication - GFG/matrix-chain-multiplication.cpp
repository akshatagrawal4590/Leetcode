//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(vector<vector<int>> &dp, int arr[], int n, int i, int j)
    {
        if(i == j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k <= j - 1; k++)
        {
            int steps = f(dp, arr, n, i, k) + f(dp, arr, n, k + 1, j) + arr[i-1] * arr[k] * arr[j];
            mini = min(mini, steps);
        }
        dp[i][j] = mini;
        return dp[i][j];
    }

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(dp, arr, n, 1, n - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends