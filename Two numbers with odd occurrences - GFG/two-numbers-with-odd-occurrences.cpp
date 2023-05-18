//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        vector<long long int> ans;
        long long int xy = 0;
        for(long long int i = 0; i < n; i++)
        {
            xy = xy ^ arr[i];
        }
        long long int xym = xy & -xy;
        long long int x = 0;
        long long int y = 0;
        long long int i = 0;
        while(i < n)
        {
            if((xym & arr[i]) == 0)
            {
                x = x ^ arr[i];
            }
            else
            {
                y = y ^ arr[i];
            }
            i++;
        }
        if(x < y)
        {
            ans.push_back(y);
            ans.push_back(x);
            return ans;
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends