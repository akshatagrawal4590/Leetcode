class Solution {
public:
    bool f(vector<int> nums, int i, int n, int x)
    {
        int j = i + 1;
        bool ans = 1;
        if(nums[i] <= x)
        {
            while(j < n)
            {
                if(nums[i] <= nums[j] && nums[j] <= x)
                {
                    i++;
                    j++;
                }
                else
                {
                    ans = 0;
                    break;
                }
            }
            return ans;
        }
        else
        {
            ans = 0;
            return ans;
        }
        
    }
    
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        bool ans = 1;
        if(n == 1)
            return ans;
        int i = 0; 
        int j = 1;
        while(j < n)
        {
            if(nums[i] <= nums[j])
            {
                i++;
                j++;
            }
            else
            {
                bool smallans = f(nums, j, n, nums[0]);
                if(smallans == true)
                    break;
                else
                {
                    ans = 0;
                    break;
                }
            }
        }
        return ans;
    }
};