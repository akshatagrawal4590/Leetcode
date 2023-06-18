class Solution {
public:
    void dfs(int sv, vector<int> &visited, vector<int> adj[])
    {
        visited[sv] = 1;
        for(auto it : adj[sv])
        {
            if(visited[it] == 0)
            {
                visited[it] = 1;
                dfs(it, visited, adj);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& g) 
    {
        int n = g.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && g[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0)
            {
                ans++;
                dfs(i, visited, adj);
            }
        }
        return ans;
    }
};