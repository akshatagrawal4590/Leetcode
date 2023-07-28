//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> q, int n) 
    {
        int x = 0;
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--)
        {
            if(q[i][0] == 0)
            {
                int a = q[i][1] ^ x;
                ans.push_back(a);
            }
            else
            {
                x = x ^ q[i][1];
            }
        }
        ans.push_back(x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,type,val;
        cin>>N;
        
        vector<vector<int>> Q;
        
        for(int i=0; i<N; i++)
        {
            cin>>type>>val;
            vector<int> temp;
            temp.push_back(type);
            temp.push_back(val);
            Q.push_back(temp);
        }

        Solution ob;
        vector<int> res = ob.constructList(Q,N);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends