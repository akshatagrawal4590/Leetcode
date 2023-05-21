class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int x = 0;
        int i = 0;
        while(nums[i] != -1)
        {
            x = nums[i];
            nums[i] = -1;
            i = x;
        }
        return i;
    }
};