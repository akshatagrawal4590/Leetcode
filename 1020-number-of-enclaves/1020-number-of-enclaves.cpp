class Solution {
public:
    int arr[5] = {-1, 0, 1, 0, -1};
    
    void bfs(int si, int sj, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(si, sj));
        visited[si][sj] = 1;
        while(q.size() != 0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int ind = 0; ind < 4; ind++)
            {
                int i = x + arr[ind];
                int j = y + arr[ind+1];
                if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0 && grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            }
        }
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j] == 1 && visited[0][j] == 0)
            {
                bfs(0, j, grid, visited);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(grid[i][m-1] == 1 && visited[i][m-1] == 0)
            {
                bfs(i, m - 1, grid, visited);
            }
        }
        for(int j = m - 1; j >= 0; j--)
        {
            if(grid[n-1][j] == 1 && visited[n-1][j] == 0)
            {
                bfs(n - 1, j, grid, visited);
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(grid[i][0] == 1 && visited[i][0] == 0)
            {
                bfs(i, 0, grid, visited);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                {
                    ans++;
                }
            }
        }
        return ans;    
    }
};