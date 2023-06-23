//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int countPaths(int n, vector<vector<int>>& roads) 
    // {
    //     vector<pair<int, int>> adj[n];
    //     for(int i = 0; i < roads.size(); i++)
    //     {
    //         adj[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
    //         adj[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
    //     }
    //     vector<long long> dis(n, 1e15);
    //     long long count = 0;
    //     priority_queue<pair<int, int>> q;
    //     q.push(make_pair(0, 0));
    //     dis[0] = 0;
    //     while(q.size() != 0)
    //     {
    //         int x = q.top().second;
    //         int y = q.top().first;
    //         q.pop();
    //         if(x == n - 1 && dis[x] > y)
    //         {
    //             count = 1;
    //             dis[x] = y;
    //             continue;
    //         }
    //         else if(x == n - 1 && dis[x] == y)
    //         {
    //             count++;
    //             continue;
    //         }
    //         else if(x != n - 1 && dis[x] > y)
    //         {
    //             dis[x] = y;
    //         }
    //         for(auto it : adj[x])
    //         {
    //             int i = it.first;
    //             int j = it.second;
    //             if(y + j <= dis[i])
    //             {
    //                 q.push(make_pair(y + j, i));
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int wt=i.second;
                int child=i.first;
                if(dist[child]>(long long)time+wt)
                {
                    dist[child]=(long long)time+wt;
                    ways[child]=ways[node];
                    pq.push({dist[child],child});
                }
                else if(dist[child]==time+wt)
                {
                    ways[child]=(ways[child]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends