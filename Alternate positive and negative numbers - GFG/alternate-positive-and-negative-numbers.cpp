//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	void rearrange(int arr[], int N) 
{
   // code here
   vector < int> p;
   vector <int > n;
   for (int i =0 ;i<N ; i++ )
   {
       if ( arr[i]>=0)
       {
           p.push_back(arr[i]);
       }
       else
       {
           n.push_back(arr[i]);
       }
   }
   
   //now all postitive elements are in vector p and all negative eleents are in vector n 
   
   int i =0 ;
   int j =0 ;
   int k =0 ;
   
   while (i <p.size() && j<n.size() )
   {
       if ( k%2==0)
       {
           arr[k++] =p[i++];
       }
       else
       {
           arr[k++]=n[j++];
       }
   }
   
   while ( i<p.size())
   {
       arr[k++]=p[i++];
   }
   while ( j < n.size())
   {
       arr[k++]=n[j++];
   }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends