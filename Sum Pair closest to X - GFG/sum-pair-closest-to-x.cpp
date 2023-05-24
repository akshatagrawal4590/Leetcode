//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        vector<int>ans(2);
        int n=arr.size();
        
         int i=0,j=n-1,k=0,sum=INT_MAX;
         while(i<j){
             k=arr[i]+arr[j];
             
             if(x>=k){
                 int mini=abs(x-k);
                 if(mini<sum){
                     ans[0]=arr[i];
                     ans[1]=arr[j];
                     sum=mini;
                 }
                 i++;
             }else{
                 int mini=abs(k-x);
                  if(mini<sum){
                     ans[0]=arr[i];
                     ans[1]=arr[j];
                     sum=mini;
                 }
                 j--;
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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends