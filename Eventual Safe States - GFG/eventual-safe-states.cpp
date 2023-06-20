//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool f(vector<int> &visited, vector<int> &pathvisited, vector<int> adj[], int sv)
    {
        for(auto it : adj[sv])
        {
            if(pathvisited[it] == 1)
            {
                return true;
            }
            visited[it] = 1;
            pathvisited[it] = 1;
            bool x = f(visited, pathvisited, adj, it);
            pathvisited[it] = 0;
            if(x == true)
            {
                return true;
            }
            else
            {
                visited[it] = 0;
            }
        }
        return false;
    }
  
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) 
    {
        vector<int> visited(v, 0);
        vector<int> pathvisited(v, 0);
        vector<int> ans;
        for(int i = 0; i < v; i++)
        {
            if(visited[i] == 0)
            {
                pathvisited[i] = 1;
                visited[i] = 1;
                bool x = f(visited, pathvisited, adj, i);
                pathvisited[i] = 0;
                if(x == false)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends