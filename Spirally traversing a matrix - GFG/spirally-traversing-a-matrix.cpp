//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        vector<int> ans;
        int imax = r;
        int jmax = c;
        int i = 0;
        int j = 0;
        int jmin = 0;
        int imin = 0;
        while(j < jmax)
        {
            while(j < jmax)
            {
                ans.push_back(mat[imin][j]);
                j++;
            }
            i++;
            imin = i;
            j--;
            if(i == imax)
            {
                break;
            }
            while(i < imax)
            {
                ans.push_back(mat[i][j]);
                i++;
            }
            i--;
            jmax = j;
            j--;
            if(j < jmin)
            {
                break;
            }
            while(j >= jmin)
            {
                ans.push_back(mat[i][j]);
                j--;
            }
            j++;
            imax = i;
            i--;
            if(i < imin)
            {
                break;
            }
            while(i >= imin)
            {
                ans.push_back(mat[i][j]);
                i--;
            }
            i++;
            j++;
            jmin = j;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends