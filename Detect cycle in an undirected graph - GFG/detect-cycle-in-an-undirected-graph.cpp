//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool f(vector<int> &visited, int i, vector<int> adj[])
    {
        queue<pair<int, int>> q;
        q.push(make_pair(i, -1));
        while(q.size() != 0)
        {
            int x = q.front().first;
            int y = q.front().second;
            visited[x] = 1;
            q.pop();
            for(auto it : adj[x])
            {
                if(visited[it] == 1 && it != y)
                {
                    return true;
                }
                else if(visited[it] == 0)
                {
                    q.push(make_pair(it, x));
                }
            }
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) 
    {
        vector<int> visited(v, 0);
        for(int i = 0; i < v; i++)
        {
            if(visited[i] == 0)
            {
                bool x = f(visited, i, adj);
                if(x == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends