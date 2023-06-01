//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int f(int l, int r, int arr[])
    {
        if(l < r)
        {
            int mid = (l + r) / 2;
            if(mid == l)
            {
                return min(arr[mid], f(mid + 1, r, arr));   
            }
            else
            {
                if(arr[mid] < arr[mid-1])
                {
                    return arr[mid];
                }
                else
                {
                    int x = f(l, mid - 1, arr);
                    int y = f(mid + 1, r, arr);
                    return min(x, y);
                }
            }
        }
        else
        {
            return arr[l];
        }
    }

    int findMin(int arr[], int n)
    {
        int l = 0;
        int r = n - 1;
        return f(l, r, arr);
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends