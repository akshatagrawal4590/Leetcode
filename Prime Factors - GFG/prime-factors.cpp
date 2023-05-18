//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	
	vector<int>AllPrimeFactors(int n) 
	{
	    vector<int> ans;
	    if(n == 1)
	    {
	        return ans;
	    }
	    int i = 2;
	    while(n != 1)
	    {
	        if(n % i == 0)
	        {
	            ans.push_back(i);
	            while(n % i == 0)
	            {
	                n = n / i;
	            }
	        }
	        i++;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends