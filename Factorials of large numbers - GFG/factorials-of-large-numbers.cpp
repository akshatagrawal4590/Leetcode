//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n)
    {
        int num = 1;
        int carry = 0;
        vector<int> ans;
        if(n == 1)
        {
            ans.push_back(1);
            return ans;
        }
        for(int i = 2; i <= n; i++)
        {
            if(ans.size() == 0)
            {
                ans.push_back(num*i);
            }
            else
            {
                int len = ans.size();
                int j = 0;
                while(j < len)
                {
                    int x = (ans[j] * i) + carry;
                    if(x >= 10)
                    {
                        ans[j] = x % 10;
                        carry = x / 10;
                    }
                    else
                    {
                        ans[j] = x;
                        carry = 0;
                    }
                    j++;
                }
                while(carry != 0)
                {
                     int x = carry % 10;
                     ans.push_back(x);
                     carry = carry / 10;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // vector<int> factorial(int n){
    //     // code here
    //     vector<int>v;
    //     v.push_back(1);
        
    //     for(int j=2;j<=n;j++)
    //     {
    //         int carry=0;
            
    //         for(int i=0;i<v.size();i++)
    //         {
    //             int data=v[i]*j+carry;
    //             v[i]=data%10;
    //             carry=data/10;
    //         }
            
    //         while(carry!=0)
    //         {
    //             v.push_back(carry%10);
    //             carry/=10;
    //         }
    //     }
    //     reverse(v.begin(),v.end());
    //     return v;
    // }
 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends