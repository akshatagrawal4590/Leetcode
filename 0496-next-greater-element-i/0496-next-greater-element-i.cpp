class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums2.size();
        stack<int> s;
        s.push(nums2[n-1]);
        unordered_map<int, int> m;
        m[nums2[n-1]] = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            while(s.size() != 0 && s.top() < nums2[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                s.push(nums2[i]);
                m[nums2[i]] = -1;
                continue;
            }
            int x = s.top();
            s.push(nums2[i]);
            m[nums2[i]] = x;
        }
        n = nums1.size();
        for(int i = 0; i < n; i++)
        {
            nums1[i] = m[nums1[i]];
        }
        return nums1;
    }
};