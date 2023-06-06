//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    int f(vector<long long> &dp, int i)
    {
        if(i == 0)
        {
            return 1;
        }
        if(i == 1 || i == 2)
        {
            return i;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        long long x = 0;
        for(int j = 1; j <= i; j++)
        {
            long long a = f(dp, j - 1) % 1000000007;
            long long b = f(dp, i - j) % 1000000007;
            x = (x + (a * b)) % 1000000007;
        }
        dp[i] = x;
        return dp[i];
    }
    
    int numTrees(int n) 
    {
        vector<long long> dp(n + 1, -1);
        return f(dp, n);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends