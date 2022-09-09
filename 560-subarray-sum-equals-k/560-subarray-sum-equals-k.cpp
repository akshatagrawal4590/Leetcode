class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        int i = 0;
        m[0] = 1;
        int ans = 0;
        while(i < n)
        {
            sum = sum + nums[i];
            if(m.count(sum - k) > 0)
                ans = ans + m[sum - k];
            m[sum]++;
            i++;
        }
        return ans;
    }
};