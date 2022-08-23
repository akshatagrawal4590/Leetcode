class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans = INT_MIN;
        int count = 0;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] == 1)
                count++;
            else
            {
                ans = max(ans, count);
                count = 0;
            }
            i++;
        }
        ans = max(ans, count);
        return ans;
    }
};