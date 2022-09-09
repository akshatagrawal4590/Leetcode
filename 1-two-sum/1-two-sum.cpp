class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(m.count(target - nums[i]) > 0)
            {
                ans.push_back(i);
                ans.push_back(m[target - nums[i]]);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};