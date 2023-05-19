//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) 
    {
        string s = "";
        while(x != 0)
        {
            if(x % 2 == 0)
            {
                s.push_back('0');
                x = x / 2;
            }
            else
            {
                s.push_back('1');
                x = x / 2;
            }
        }
        //cout<<s<<endl;
        int m = 31;
        int i = 0;
        int l = s.length();
        long long ans = 0;
        while(i != l)
        {
            if(s[i] == '1')
            {
                ans = ans + pow(2, m);
            }
            m--;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends