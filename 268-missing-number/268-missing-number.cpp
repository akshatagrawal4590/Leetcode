class Solution {
public:
    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = ans ^ arr[i];
        for(int i = 0; i <= n; i++)
            ans = ans ^ i;
        return ans;
    }
};