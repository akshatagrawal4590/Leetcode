//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int x=0;
        for(int i=0;i<n;i++)
        {
             x^=arr[i];
             x^=(i+1);
        }
        // cout<<x<<endl;
        int y=x&(-x);
        // cout<<y<<endl;
        int k=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&y)
            k^=arr[i];
            else
            l^=arr[i];
            
            if((i+1)&y)
            k^=i+1;
            else
            l^=i+1;
        }
        vector<int>ans(2,0);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==k||arr[i]==l)
            {
                ans[0]=arr[i];
                ans[1]=arr[i]^x;
                break;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends