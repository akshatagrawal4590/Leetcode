//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int check(string &s, int l, int r)
    {
        int i = 0;
        int j = s.length() - 1;
        int ans = 0;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(i >= l && i <= r && j >= l && j <= r)
                {
                    return -1;
                }
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
    
    int specialPalindrome(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int ans = INT_MAX;
        for(int i = 0; i <= n1 - n2; i++)
        {
            int temp = 0;
            string s = s1;
            int k = i;
            for(int j = 0; j < n2; j++)
            {
                if(s[k] == s2[j])
                {
                    k++;
                }
                else
                {
                    s[k] = s2[j];
                    k++;
                    temp++;
                }
            }
            int y = check(s, i, k - 1);
            if(y != -1)
            {
                ans = min(ans, temp + y);   
            }
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends