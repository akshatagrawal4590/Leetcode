class Solution {
public:
    int arr[9] = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        {
            return -1;
        }
        vector<vector<int>> visited(n, vector<int> (n, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int count = 0;
        visited[0][0] = 1;
        pair<int, int> p(n-1, n-1);
        while(q.size() != 0)
        {
            int len = q.size();
            for(int i1 = 0; i1 < len; i1++)
            {
                if(q.front() == p)
                {
                    return count + 1;
                }
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int it = 0; it < 8; it++)
                {
                    int i = x + arr[it];
                    int j = y + arr[it+1];
                    if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0 && visited[i][j] == 0)
                    {
                        visited[i][j] = 1;
                        q.push(make_pair(i, j));
                    }
                }
            }
            count++;
        }
        return -1;
    }
};