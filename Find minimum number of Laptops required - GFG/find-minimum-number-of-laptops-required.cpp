//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    int minLaptops(int n, int start[], int end[]) 
    {
        sort(start, start + n);
        sort(end, end + n);
        int ans = 1;
        int count = 1;
        int i = 1;
        int j = 0;
        while(i < n && j < n)
        {
            //cout<<i<<" "<<j<<" "<<count<<endl;
            if(start[i] == start[i-1])
            {
                count++;
                i++;
                ans = max(ans, count);
            }
            else if(start[i] < end[j])
            {
                count++;
                i++;
                ans = max(ans, count);
            }
            else if(start[i] >= end[j])
            {
                while(j < n)
                {
                    if(end[j] <= start[i])
                    {
                        count--;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                i++;
                count++;
                ans = max(ans, count);
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
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends