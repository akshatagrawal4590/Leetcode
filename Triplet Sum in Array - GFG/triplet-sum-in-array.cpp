//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    int f(int a[], int n, int x, int ind)
    {
        int i = 0;
        int j = n - 1;
        while(i < j)
        {
            if(i == ind)
            {
                i++;
            }
            else if(j == ind)
            {
                j--;
            }
            else if(a[i] + a[j] == x)
            {
                return 1;
            }
            else if(a[i] + a[j] < x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return 0;
    }
    
    bool find3Numbers(int a[], int n, int x)
    {
        sort(a, a + n);
        for(int i = 0; i < n; i++)
        {
            if(a[i] > x)
            {
                return false;
            }
            else
            {
                int temp = f(a, n, x - a[i], i);
                if(temp == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends