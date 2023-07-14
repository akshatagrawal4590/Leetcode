//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) 
    {
        int a1 = a;
        vector<int> v;
        while(a != 0)
        {
            v.push_back(a % 2);
            a = a / 2;
        }
        int bits = 0;
        int n = ceil(log2(b));
        int i = 1;
        while(i <= n)
        {
            if(b & (1 << i - 1))
            {
                bits++;
            }
            i++;
        }
        n = v.size();
        i = n - 1;
        int ans = 0;
        while(i >= 0)
        {
            if(v[i] == 1 && bits > 0)
            {
                bits--;
            }
            else if(v[i] == 1 && bits == 0)
            {
                v[i] = 0;
            }
            else if(bits == i + 1)
            {
                v[i] = 1;
                bits--;
            }
            ans = ans + v[i] * pow(2, i);
            i--;
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