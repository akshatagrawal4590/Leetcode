//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int arr[5] = {-1, 0, 1, 0, -1};  
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        q.push(source);
        int count = 0;
        visited[source.first][source.second] = 1;
        while(q.size() != 0)
        {
            int len = q.size();
            for(int i1 = 0; i1 < len; i1++)
            {
                if(q.front() == destination)
                {
                    return count;
                }
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int it = 0; it < 4; it++)
                {
                    int i = x + arr[it];
                    int j = y + arr[it+1];
                    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && visited[i][j] == 0)
                    {
                        visited[i][j] = 1;
                        q.push(make_pair(i, j));
                    }
                }
            }
            count++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends