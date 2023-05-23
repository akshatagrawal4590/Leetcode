//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
    int max_path_sum(int a[], int b[], int l1, int l2)
    {
        int ans = 0;
        if(a[l1-1] == b[0] || a[0] == b[l2-1])
        {
            for(int i = 0; i < l1; i++)
            {
                ans = ans + a[i];
            }
            for(int i = 0; i < l2; i++)
            {
                ans = ans + b[i];
            }
            if(a[l1-1] == b[0])
            {
                return ans - b[0];
            }
            return ans - a[0];
        }
        int s1 = 0;
        int s2 = 0;
        int i = 0;
        int j = 0;
        while(i < l1 && j < l2)
        {
            if(a[i] == b[j])
            {
                ans = ans + max(s1, s2) + a[i];
                s1 = 0;
                s2 = 0;
                i++;
                j++;
            }
            else if(a[i] < b[j])
            {
                s1 = s1 + a[i];
                i++;
            }
            else
            {
                s2 = s2 + b[j];
                j++;
            }
        }
        if(i == l1 && j != l2)
        {
            while(j < l2)
            {
                s2 = s2 + b[j];
                j++;
            }
        }
        else if(i != l1 && j == l2)
        {
            while(i < l1)
            {
                s1 = s1 + a[i];
                i++;
            }
        }
        ans = ans + max(s1, s2);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends