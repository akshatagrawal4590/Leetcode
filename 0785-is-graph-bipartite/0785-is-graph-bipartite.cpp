class Solution {
public:
    bool f(vector<pair<int, int>> &visited, vector<vector<int>> &graph, int n, int sv)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(sv, 1));
        visited[sv] = make_pair(1, 1);
        while(q.size() != 0)
        {
            int x = q.front().first;
            int color = q.front().second;
            q.pop();
            for(auto it  : graph[x])
            {
                if(color == 1)
                {
                    if(visited[it].first == 0)
                    {
                        visited[it] = make_pair(1, 2);
                        q.push(make_pair(it, 2));
                    }
                    else if(visited[it].second == color)
                    {
                        return false;
                    }
                }
                else
                {
                    if(visited[it].first == 0)
                    {
                        visited[it] = make_pair(1, 1);
                        q.push(make_pair(it, 1));
                    }
                    else if(visited[it].second == color)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<pair<int, int>> visited(n, make_pair(0, -1));
        for(int i = 0; i < n; i++)
        {
            if(visited[i].first == 0)
            {
                bool x = f(visited, graph, n, i);
                if(x == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};