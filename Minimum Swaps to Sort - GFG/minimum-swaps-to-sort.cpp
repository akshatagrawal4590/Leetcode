//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> v;
	    int n = nums.size();
	    unordered_map<int, int> m;
	    for(int i = 0; i < n; i++)
	    {
	        v.push_back(nums[i]);
	        m[nums[i]] = i;
	    }
	    sort(v.begin(), v.end());
	    int ans = 0;
	    for(int i = 0; i < n; i++)
	    {
	        if(nums[i] != v[i])
	        {
	            ans++;
	            int x = m[v[i]];
	            nums[x] = nums[i];
	            nums[i] = v[i];
	            m[v[i]] = i;
	            m[nums[x]] = x;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends