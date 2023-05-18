//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<bool> prime(10001, 1);
        prime[0] = prime[1] = 0;
        for(int i=2; i*i<=n; i++) {
            if(prime[i])
                for(int j=i*i; j<=n; j += i)
                    prime[j] = 0;
        }
        vector<int> ans;
        for(int i=2; i<=n; i++) {
            if(prime[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends