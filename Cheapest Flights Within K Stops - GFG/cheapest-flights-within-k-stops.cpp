//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  
    {
        // vector<pair<int, int>> adj[n];
        // for(int i = 0; i < flights.size(); i++)
        // {
        //     int x = flights[i][0];
        //     int y = flights[i][1];
        //     int z = flights[i][2];
        //     adj[x].push_back(make_pair(y, z));
        // }
        // vector<pair<int, int>> dis(n, make_pair(INT_MAX, INT_MAX));
        // queue<pair<int, int>> q;
        // q.push(make_pair(0, src));
        // k++;
        // int ans = INT_MAX;
        // dis[0] = make_pair(0, 0);
        // while(q.size() != 0)
        // {
        //     int l = q.size();
        //     while(l > 0)
        //     {
        //         int x = q.front().second;
        //         int y = q.front().first;
        //         q.pop();
        //         if(x == dst)
        //         {
        //             ans = min(ans, y);
        //             l--;
        //             continue;
        //         }
        //         else if(k == 0)
        //         {
        //             l--;
        //             continue;
        //         }
        //         for(auto it : adj[x])
        //         {
        //             int i = it.first;
        //             int j = it.second;
                    
        //             q.push(make_pair(y + j, i));
        //         }
        //         l--;
        //     }
        //     k--;
        // }
        // if(ans == INT_MAX)
        // {
        //     return -1;
        // }
        // return ans;
        vector <vector<vector<int>>> adj(n);
int m = flights.size();
for(int i = 0;i < m;i++)
    adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
vector <int> dist(n,INT_MAX);
dist[src] = 0;
queue <vector<int>> pq;
pq.push({0,src,0});
while(!pq.empty()){
    int price = pq.front()[0], flight = pq.front()[1],stops = pq.front()[2];
    pq.pop();
    for(auto it:adj[flight]){
        int next = it[0];
        int newPrice = price+it[1];
        if(stops <= k && dist[next] > newPrice){
            dist[next] = newPrice;
            pq.push({newPrice,next,stops+1});
        }
    }
}
return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends