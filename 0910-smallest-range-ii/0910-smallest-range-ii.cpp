class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int result = INT_MAX;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n - 1; i++)
        {
            int mini = min(arr[0] + k, arr[i+1] - k);
            int maxi = max(arr[i] + k, arr[n-1] - k);
            result = min(result, maxi - mini);
        }
        result = min(result, arr[n-1] - arr[0]);
        return result;
    }
};