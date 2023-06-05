//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    bool solve(string A,string B,string C,int a,int b,int c,vector<vector<int>>&dp)
    {
        //base case
        
        if(c>=C.size() && a>=A.size() && b>=B.size())
        {
            return true;
        }
        if(dp[a][b]!=-1)
        return dp[a][b];
        
        
        
        bool x=false,y=false;
        if(A[a]==C[c] && a<A.size() && c<C.size())
        {
            x = solve(A,B,C,a+1,b,c+1,dp);
        }
        
        if(B[b]==C[c] && b<B.size() && c<C.size())
        {
            y = solve(A,B,C,a,b+1,c+1,dp);
        }
      
        int ans = x||y;
        dp[a][b] = ans;
        return ans;
   
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        vector<vector<int>>dp(A.size()+1,vector<int>(B.size()+1,-1));
        return solve(A,B,C,0,0,0,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends