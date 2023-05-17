//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
         int ans = 0; 
        for(int i = 0; i < 31; i++) {
            
            int x = 1ll << i; 
            int y = max(0ll, (n % (2 * x)) - x + 1ll); 
            int z = (n / (2 * x)) * x;
            ans += (n / (2 * x)) * x + y; 
        }
        return ans; 
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends