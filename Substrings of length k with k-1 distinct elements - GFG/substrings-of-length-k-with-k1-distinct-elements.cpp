//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) 
    {
        unordered_map<char, int> m;
        int n = s.length();
        int ans = 0;
        int i = 0;
        int x = k;
        for(int j = 0; j < n; j++)
        {
            if(x != 0)
            {
                x--;
                m[s[j]]++;
            }
            else
            {
                if(m.size() == k - 1)
                {
                    ans++;
                }
                if(m[s[i]] == 1)
                {
                    m.erase(s[i]);
                }
                else
                {
                    m[s[i]]--;
                }
                m[s[j]]++;
                i++;
            }
            // for(auto it : m)
            // {
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            // cout<<"--------------------"<<endl;
        }
        if(m.size() == k - 1)
        {
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends