//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) 
    {
        unordered_map<int, int> m;
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(m.count(arr[i]) == 0)
            {
                m[arr[i]] = i;
            }
            else
            {
                if(ans == -1)
                {
                    ans = m[arr[i]];
                }
                else
                {
                    ans = min(ans, m[arr[i]]);
                }
            }
        }
        if(ans == -1)
        {
            return ans;
        }
        return ans + 1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends