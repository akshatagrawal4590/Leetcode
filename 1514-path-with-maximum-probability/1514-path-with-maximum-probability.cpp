class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
        vector<pair<int, double>> adj[n];
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        vector<double> dist(n, INT_MIN);
        priority_queue<pair<double, int>> q;
        q.push(make_pair(1, start));
        dist[start] = 1;
        while(q.size() != 0)
        {
            double y = q.top().first;
            int x = q.top().second;
            q.pop();
            dist[x] = y;
            if(x == end)
            {
                break;
            }
            for(auto it : adj[x])
            {
                int i = it.first;
                double j = it.second;
                if(dist[i] < y * j)
                {
                    q.push(make_pair(y * j, i));
                }
            }
        }
        if(dist[end] == INT_MIN)
        {
            return 0;
        }
        return dist[end];
    }
};