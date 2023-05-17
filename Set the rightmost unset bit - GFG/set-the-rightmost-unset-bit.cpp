//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        if(floor(log2(n+1)) == ceil(log2(n+1)))
        {
            return n;
        }
        int i = 1;
        while(1)
        {
            int y = i & n;
            if(y == 0)
            {
                return i | n;
            }
            else
            {
                i = i << 1;
                continue;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends