//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n = matrix.size();
        vector<int> ans;
        int j = 0;
        int i = 0;
        while(j < n)
        {
            int y = j;
            int x = i;
            while(x < n && y >= 0)
            {
                ans.push_back(matrix[x][y]);
                x++;
                y--;
            }
            j++;
        }
        i++;
        j--;
        while(i < n)
        {
            int x = i;
            int y = j;
            while(x < n && y >= 0)
            {
                ans.push_back(matrix[x][y]);
                x++;
                y--;
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends