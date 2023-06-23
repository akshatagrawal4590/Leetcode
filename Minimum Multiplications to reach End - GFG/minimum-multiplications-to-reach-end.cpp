//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>pq;
        pq.push({0,start});
        vector<int>v(100000,-1);
        v[start]=0;
        while(!pq.empty())
            {
                int steps=pq.front().first;
                int product=pq.front().second;
                pq.pop();
                for(auto i:arr)
                {
                    int mul=i*product;
                    mul=mul%100000;
                    if(mul==end)return steps+1;
                    if(v[mul]==-1)
                    {
                        pq.push({steps+1,mul});
                        v[mul]=steps+1;
                    }
                }
            }
        
        return v[end] ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends