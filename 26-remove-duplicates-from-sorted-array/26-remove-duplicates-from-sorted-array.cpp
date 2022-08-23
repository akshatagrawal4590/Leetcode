class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return 1;
        int i = 0;
        int j = 0;
        int last = nums[i];
        while(j < n)
        {
            if(nums[j] == last)
            {
                j++;
            }
            else
            {
                nums[i+1] = nums[j];
                i++;
                j++;
                last = nums[i];
            }
        }
        return i + 1;
    }
};