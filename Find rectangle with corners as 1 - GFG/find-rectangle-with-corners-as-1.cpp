//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int arr[5] = {-1, 0, 1, 0, -1};
    
    bool ValidCorner(vector<vector<int> >& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 1)
                {
                    for(int k = j + 1; k < m; k++)
                    {
                        if(matrix[i][k] == 1)
                        {
                            int x = k - j;
                            for(int l = i + 1; l < n; l++)
                            {
                                if(matrix[l][k] == 1 && matrix[l][k-x] == 1)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
                matrix[i][j] = 0;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 



// } Driver Code Ends