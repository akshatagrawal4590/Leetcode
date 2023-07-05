//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int arr[9] = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

	int f(vector<vector<char>> &grid, string &word, int x, int y, int i, int j, int l, int n, int m)
	{
	    if(l == word.length())
	    {
	        return 1;
	    }
	    x = x + i;
	    y = y + j;
	    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == word[l])
	    {
	        return f(grid, word, x, y, i, j, l + 1, n, m);
	    }
	    return 0;
	}
	
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == word[0])
	            {
	                for(int ind = 0; ind < 8; ind++)
	                {
	                    int x = f(grid, word, i, j, arr[ind], arr[ind+1], 1, n, m);
	                    if(x == 1)
                        {
                            vector<int> v{i, j};
                            ans.push_back(v);
                            break;
                        }
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends