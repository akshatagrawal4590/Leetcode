//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    
    //
    vector<int> rank, parent;
    
    public:
    
    //
    DisjointSet(int n){
        
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i=0; i<n+1; i++) parent[i] = i;
    }
    
    //
    void unionByRank(int u, int v){
        
        int up_u = findUparent(u);
        int up_v = findUparent(v);
        
        if(up_u == up_v) return;
        
        if(rank[up_u] == rank[up_v]){
            
            parent[up_v] = up_u;
            rank[up_u] += 1;
        }
        else if(rank[up_u] > rank[up_v]){
            
            parent[up_v] = up_u;
        }
        else if(rank[up_u] < rank[up_v]){
            
            parent[up_u] = up_v;
        }
        
    }
    
    //
    int findUparent(int x){
        
        if(parent[x] == x) return x;
        
        return parent[x] = findUparent(parent[x]);
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        //
        DisjointSet djs(n);
        int m = edge.size(); // #edges
        
        //
        for(int i=0; i<m; i++){
            
            int u = edge[i][0];
            int v = edge[i][1];
            
            //
            djs.unionByRank(u, v);
        }
        
        //
        unordered_set<int> st;
        
        //
        for(int i=0; i<n; i++) st.insert(djs.findUparent(i));
        
        // st.size() = #ultimate parent = #components of a given graph
        
        return (m >= n-1)? st.size()-1 : -1; // at least n-1 edges required for connecting grpah
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends