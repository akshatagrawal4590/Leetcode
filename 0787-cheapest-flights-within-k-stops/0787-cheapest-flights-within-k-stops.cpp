class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < flights.size(); i++)
        {
            int x = flights[i][0];
            int y = flights[i][1];
            int z = flights[i][2];
            adj[x].push_back(make_pair(y, z));
        }
        vector <int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<vector<int>> q;
        k++;
        vector<int> v1 = {0, 0, src};
        q.push(v1);
        while(q.size() != 0)
        {
            int x = q.front()[2];
            int y = q.front()[1];
            int z = q.front()[0];
            q.pop();
            if(z >= k)
            {
                continue;
            }
            for(auto it : adj[x])
            {
                int i = it.first;
                int j = it.second;
                if(y + j < dist[i] && z + 1 <= k)
                {
                    vector<int> v = {z + 1, y + j, i};
                    q.push(v);
                    dist[i] = y + j;
                }
            }
        }
        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};