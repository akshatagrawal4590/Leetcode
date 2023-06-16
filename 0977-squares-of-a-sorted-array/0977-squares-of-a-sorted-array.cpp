class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] < 0)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        int j = i;
        i = i - 1;
        while(i >= 0 && j < n)
        {
            int x = nums[j] * nums[j];
            int y = nums[i] * nums[i];
            if(x > y)
            {
                ans.push_back(y);
                i--;
            }
            else
            {
                ans.push_back(x);
                j++;
            }
        }
        if(i >= 0)
        {
            while(i >= 0)
            {
                int y = nums[i] * nums[i];
                ans.push_back(y);
                i--;
            }
        }
        if(j < n)
        {
            while(j < n)
            {
                int x = nums[j] * nums[j];
                ans.push_back(x);
                j++;
            }
        }
        return ans;
    }
};