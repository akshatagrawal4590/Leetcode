class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s;
        int n1 = nums1.size();
        for(int i = 0; i < n1; i++)
            s.insert(nums1[i]);
        int n2 = nums2.size();
        vector<int> ans;
        for(int i = 0; i < n2; i++)
        {
            auto it = s.find(nums2[i]);
            if(it != s.end())
            {
                ans.push_back(nums2[i]);
                s.erase(it);
            }
        }
        return ans;
    }
};