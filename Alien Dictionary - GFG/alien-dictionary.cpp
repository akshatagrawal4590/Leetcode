//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        int maxlen = INT_MIN;
        for(int i=0; i<n; i++) maxlen = max(maxlen, (int)dict[i].length());
        vector<vector<int>> adj(k);
        
        //building adj list
        for(int i=0; i<maxlen; i++){
            for(int j=0; j<n-1; j++){
                if(dict[j].substr(0,i) == dict[j+1].substr(0,i)){
                    char c1 = dict[j].substr(i)[0];
                    char c2 = dict[j+1].substr(i)[0];
                    if(c1 and c2 and c1!=c2) adj[c1-'a'].push_back(c2-'a');
                }
            }
        }
        
        //topological sort via dfs
        string ans = "";
        vector<bool> visited(k, 0); 
        for(int i=0; i<k; i++){
            if(!visited[i]) dfs(i, ans, visited, adj);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(int i, string &ans, vector<bool> &visited, vector<vector<int>>& adj){
        visited[i] = 1;
        for(int n: adj[i]){
            if(!visited[n]) dfs(n, ans, visited, adj);
        }
        ans.push_back('a'+i);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends