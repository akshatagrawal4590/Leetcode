//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int ans=0;
        int tbs = __builtin_popcount(b);
        
        for(int i =31;i>=0;i--){
            if(tbs > 0 and (a&(1<<i))){
                ans|=(1LL<<i);
                tbs--;
            }
        }
        for(int i =0;i<31;i++){
            if(tbs > 0 and (a&(1LL<<i)) == 0 ){
                ans|=(1<<i);
                tbs--;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends