//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int arr[5] = {-1, 0, 1, 0, -1};
    
    int minIteration(int n, int m, int x, int y)
    {    
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        x--;
        y--;
        q.push({x, y});
        vis[x][y] = 1;
        int count = -1;
        while(q.size() != 0)
        {
            int l = q.size();
            count++;
            for(int it = 0; it < l; it++)
            {
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int x = p.first + arr[i];
                    int y = p.second + arr[i+1];
                    if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0)
                    {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends