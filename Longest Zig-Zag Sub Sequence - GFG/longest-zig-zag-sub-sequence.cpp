//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    
		int ZigZagMaxLength(vector<int>&nums)
		{
		    if(nums.size() <= 1) return nums.size();
            int up = 1, down = 1;
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] < nums[i+1]) // up case
                    up = down + 1;
                else if(nums[i] > nums[i+1]) // down case
                    down = up + 1;
            }
            return max(up, down);
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
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends