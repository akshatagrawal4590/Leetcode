class Solution {
public:
    void bfs(vector<vector<int>> adj, vector<int> &visited, int v, int sv)
    {
        queue<int> q;
        q.push(sv);
        visited[sv] = 1;
        while(q.size() != 0)
        {
            int x = q.front();
            q.pop();
            for(int i = 0; i < v; i++)
            {
                if(x != i && visited[i] == 0 && adj[x][i] == 1)
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& adj) 
    {
        int v = adj.size();
        vector<int> visited(v, 0);
        int ans = 0;
        for(int i = 0; i < v; i++)
        {
            if(visited[i] != 1)
            {    
                bfs(adj, visited, v, i);
                ans++;
            }
        }
        return ans;
    }
};