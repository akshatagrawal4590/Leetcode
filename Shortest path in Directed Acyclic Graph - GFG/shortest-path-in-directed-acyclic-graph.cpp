//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(vector<int> &ans, int sv, vector<pair<int, int>> adj[])
    {
        queue<pair<int, int>> q;
        q.push(make_pair(sv, 0));
        while(q.size() != 0)
        {
            int x = q.front().first;
            int y = q.front().second;
            ans[x] = min(ans[x], y);
            q.pop();
            for(auto it : adj[x])
            {
                int a = it.first;
                int b = it.second;
                q.push(make_pair(a, y + b));
            }
        }
    }
  
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < m; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            int z = edges[i][2];
            adj[x].push_back(make_pair(y, z));
        }
        //vector<int> visited[]
        vector<int> ans(n, INT_MAX);
        bfs(ans, 0, adj);
        for(int i = 0; i < n; i++)
        {
            if(ans[i] == INT_MAX)
            {
                ans[i] = -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends