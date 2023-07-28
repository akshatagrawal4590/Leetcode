//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int timer = 0;
	void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
{
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] == parent)
        {
            continue;
        }
        if (visited[adj[node][i]] == 0)
        {
            dfs(adj[node][i], node, visited, adj, tin, low, bridges);
            low[node] = min(low[node], low[adj[node][i]]);
            if (low[adj[node][i]] > tin[node])
            {
                if(node>adj[node][i]){
                   bridges.push_back({adj[node][i],node});
                }else{
                   bridges.push_back({node,adj[node][i]});
                }
            }
        }
        else
        {
            low[node] = min(low[node], low[adj[node][i]]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<int> adj[])
{
    // Code here
    vector<int> visited(n, 0);
    int tin[n];
    int low[n];
    int count = 0;
    vector<vector<int>> bridges;
    dfs(0, -1, visited, adj, tin, low, bridges);
    sort(bridges.begin(),bridges.end());
    return bridges;
}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends