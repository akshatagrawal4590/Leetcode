//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int arr[5] = {-1, 0, 1, 0, -1};
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int> (m, 0));
	    queue<pair<int, int>> q;
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push(make_pair(i, j));
	                visited[i][j] = 1;
	                grid[i][j] = 0;
	            }
	        }
	    }
	    int a = 0;
	    while(q.size() != 0)
	    {
	        int len = q.size();
	        //cout<<len<<endl;
            a++;
            while(len > 0)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int ind = 0; ind < 5; ind++)
                {
                    int i = x + arr[ind];
                    int j = y + arr[ind+1];
                    if(i >= 0 && i < n && j >= 0 && j < m)
                    {
                        if(visited[i][j] == 0 && grid[i][j] == 0)
                        {
                            grid[i][j] = a;
                            visited[i][j] = 1;
                            q.push(make_pair(i, j));
                        }
                    }
                }
                len--;
            }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends