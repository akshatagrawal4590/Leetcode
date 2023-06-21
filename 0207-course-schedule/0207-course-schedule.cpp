class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(int i = 0; i < pre.size(); i++)
        {
            int a = pre[i][0];
            int b = pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        vector<int> visited(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while(q.size() != 0)
        {
            int x = q.front();
            q.pop();
            topo.push_back(x);
            for(auto it : adj[x])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(topo.size() == n)
        {
            return true;
        }
        return false;
    }
};