//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &a) 
    {
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return -1;
        }
        int rsum = 0;
        for(int i = 0; i < n; i++)
        {
            rsum = rsum + a[i];
        }
        int lsum = 0;
        for(int i = 0; i < n; i++)
        {
            rsum = rsum - a[i];
            if(lsum == rsum)
            {
                return i + 1;
            }
            lsum = lsum + a[i];
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends