class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();
        int x = v[0][0];
        int y = v[0][1];
        for(int i = 1; i < n; i++)
        {
            if(v[i][0] <= y)
            {
                y = max(y, v[i][1]);
            }
            else
            {
                ans.push_back({x, y});
                x = v[i][0];
                y = v[i][1];
            }
        }
        ans.push_back({x, y});
        return ans;
    }
};