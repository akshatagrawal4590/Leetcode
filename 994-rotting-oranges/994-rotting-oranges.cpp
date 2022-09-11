class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0)
            return 0;
        int arr[] = {-1, 0, 1, 0, -1};
        int ans = 0;
        while(q.size() != 0)
        {
            int len = q.size();
            for(int a = 0; a < len; a++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(int x = 0; x < 4; x++)
                {
                    int i1 = i + arr[x];
                    int j1 = j + arr[x+1];
                    if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)
                    {
                        if(grid[i1][j1] == 1)
                        {
                            q.push(make_pair(i1, j1));
                            grid[i1][j1] = 2;
                            fresh--;
                        }
                    }
                }
            }
            ans++;
            if(fresh == 0)
                break;
        }
        if(fresh != 0)
            return -1;
        return ans;
    }
};