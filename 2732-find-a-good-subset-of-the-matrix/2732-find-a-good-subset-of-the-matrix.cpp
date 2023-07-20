class Solution {
public:
    
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v(m, 0);
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            if(grid[i] == v)
            {
                ans.push_back(i);
                return ans;
            }
            int x = 0;
            int j = 0;
            while(j < m)
            {
                x = x + grid[i][j] * pow(2, m - j - 1);
                j++;
            }
            mp[x] = i;
        }
        // for(auto it : mp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i = 1; i < 32; i++)
        {
            for(int j = 1; j < 32; j++)
            {
                if((i & j) == 0 && mp.count(i) > 0 && mp.count(j) > 0)
                {
                    ans.push_back(mp[i]);
                    ans.push_back(mp[j]);
                    sort(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
        return ans;
    }
};