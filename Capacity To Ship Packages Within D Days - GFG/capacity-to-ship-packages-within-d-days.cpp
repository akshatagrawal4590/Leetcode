//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool f(int cap, int arr[], int n, int d)
    {
        int load = 0;
        int days = 0;
        for(int i = 0; i < n; i++)
        {
            if(load + arr[i] <= cap)
            {
                load = load + arr[i];
            }
            else
            {
                days++;
                load = arr[i];
            }
        }
        days++;
        if(days <= d)
        {
            return true;
        }
        return false;
    }
    
    int leastWeightCapacity(int arr[], int n, int d) 
    {
        int mini = INT_MIN;
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            maxi = maxi + arr[i];
            mini = max(mini, arr[i]);
        }
        // cout<<mini<<" "<<maxi<<endl;
        int ans = -1;
        while(mini <= maxi)
        {
            int mid = (maxi + mini) / 2;
            bool x = f(mid, arr, n, d);
            if(x == true)
            {
                ans = mid;
                maxi = mid - 1;
            }
            else
            {
                mini = mid + 1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends