//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            if(m.count(arr[i]) == 0)
            {
                m[arr[i]] = 1;
            }
        }
        int i = 0;
        int ans = 0;
        while(i < n)
        {
            int x = arr[i];
            if(m.count(x-1) > 0)
            {
                i++;
            }
            else
            {
                int count = 1;
                int j = 1;
                while(m.count(x+j) > 0)
                {
                    count++;
                    j++;
                }
                ans = max(ans, count);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends