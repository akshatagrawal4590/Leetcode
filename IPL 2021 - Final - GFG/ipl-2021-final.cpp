//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) 
    {
        stack<char> ch;
        stack<int> in;
        in.push(-1);
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                ch.push(s[i]);
                in.push(i);
            }
            else
            {
                if(ch.size() != 0 && ch.top() == '(')
                {
                    ch.pop();
                    in.pop();
                    ans = max(ans, i - in.top());
                }
                else
                {
                    in.push(i);
                }
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
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends