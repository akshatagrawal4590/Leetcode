class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        int arr[5] = {-1, 0, 1, 0, -1};
        int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int> (m, 0));
	    queue<pair<int, int>> q;
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 0)
	            {
	                q.push(make_pair(i, j));
	                visited[i][j] = 1;
	                grid[i][j] = 0;
	            }
	        }
	    }
	    int a = 0;
	    while(q.size() != 0)
	    {
	        int len = q.size();
	        //cout<<len<<endl;
            a++;
            while(len > 0)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int ind = 0; ind < 4; ind++)
                {
                    int i = x + arr[ind];
                    int j = y + arr[ind+1];
                    if(i >= 0 && i < n && j >= 0 && j < m)
                    {
                        if(visited[i][j] == 0 && grid[i][j] == 1)
                        {
                            grid[i][j] = a;
                            visited[i][j] = 1;
                            q.push(make_pair(i, j));
                        }
                    }
                }
                len--;
            }
	    }
	    return grid;
    }
};