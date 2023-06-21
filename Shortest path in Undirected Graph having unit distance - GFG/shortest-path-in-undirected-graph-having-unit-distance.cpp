//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(vector<int> &ans, vector<int> &visited, vector<int> adj[], int sv)
    {
        queue<int> q;
        q.push(sv);
        int count = 0;
        visited[sv] = 1;
        while(q.size() != 0)
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                int x = q.front();
                q.pop();
                ans[x] = count;
                for(auto it : adj[x])
                {
                    if(visited[it] == 0)
                    {
                        visited[it] = 1;
                        q.push(it);
                    }                    
                }
            }
            count++;
        }
        return;
    }
  
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        vector<int> adj[n];
        for(int i = 0; i < m; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> visited(n, 0);
        vector<int> ans(n, -1);
        bfs(ans, visited, adj, src);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends