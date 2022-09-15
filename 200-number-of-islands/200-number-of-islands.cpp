class Solution {
public:
    void bfs(vector<vector<char>> &grid, int si, int sj, int m, int n)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(si, sj));
        grid[si][sj] = 2;
        int arr[] = {-1, 0, 1, 0, -1};
        while(q.size() != 0)
        {
            int len = q.size();
            for(int it = 0; it < len; it++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(int a = 0; a < 4; a++)
                {
                    int i1 = i + arr[a];
                    int j1 = j + arr[a+1];
                    if(i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && grid[i1][j1] == '1')
                    {
                        grid[i1][j1] = '2';
                        q.push(make_pair(i1, j1));
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
};