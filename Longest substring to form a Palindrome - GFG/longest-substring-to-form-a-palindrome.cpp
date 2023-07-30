//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int longestSubstring(string S) {
        int length=0,mask=0;
        unordered_map<int,int> helper;
        helper[mask]=-1;
        for(int i=0;i<S.size();i++){
            mask^=(1<<(S[i]-'a'));
            if(helper[mask])length=max(length,i-helper[mask]);
            else helper[mask]=i;
            for(int j=0;j<26;j++){
                int mask2=mask^(1<<j);
                if(helper[mask2])length=max(length,i-helper[mask2]);
            }
        }
        return length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}
// } Driver Code Ends