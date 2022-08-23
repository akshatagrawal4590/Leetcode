class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++)
            v[arr[i]-1]++;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(v[i] > 1)
                ans.push_back(i+1);
        }
        return ans;
    }
};