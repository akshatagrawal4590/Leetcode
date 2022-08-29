class Solution {
public:
    void rotate(vector<int>& arr, int k) 
    {
        int n = arr.size();
        k = k % n;
        int x = n - k;
        reverse(arr.begin(), arr.begin() + x);
        reverse(arr.begin() + x, arr.begin() + n);
        reverse(arr.begin(), arr.begin() + n);
    }
};