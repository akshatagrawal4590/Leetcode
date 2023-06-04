class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int ans = INT_MAX;
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++)
        {
            x = x + nums[i];
        }
        if(x < target)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while(j < n)
        {
            if(count < target)
            {
                count = count + nums[j];
                j++;
            }
            else
            {
                while(count >= target)
                {
                    ans = min(ans, j - i);
                    count = count - nums[i];
                    i++;
                }
            }
        }
        if(j == n && count >= target)
        {
            while(count >= target)
            {
                ans = min(ans, j - i);
                count = count - nums[i];
                i++;
            }
        }
        return ans;
    }
};