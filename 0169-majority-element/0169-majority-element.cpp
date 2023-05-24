class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int i = 0;
        int n = nums.size();
        int life = 0;
        int candidate = nums[0];
        while(i < n)
        {
            if(nums[i] == candidate)
            {
                life++;
            }
            else if(life == 0)
            {
                candidate = nums[i];
                life++;
            }
            else
            {
                life--;
            }
            i++;
        }
        return candidate;
    }
};