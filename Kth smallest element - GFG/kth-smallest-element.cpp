//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int lomuto(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j=low; j<= high - 1; j++) {
            if (pivot >= arr[j]) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r + 1;
        while (l <= r) {
            int pi = lomuto(arr, l, r);
            if (pi == k - 1) 
                return arr[pi];
            else if (pi > k - 1)
                r = pi - 1;
            else
                l = pi + 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends