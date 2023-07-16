//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        stack<long long> s;
        s.push(arr[n-1]);
        arr[n-1] = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            while(s.size() != 0 && s.top() < arr[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                s.push(arr[i]);
                arr[i] = -1;
                continue;
            }
            int x = s.top();
            s.push(arr[i]);
            arr[i] = x;
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends