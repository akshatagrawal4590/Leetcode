class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int ans = false;
        for(int i = 0; i < n; i++)
        {
            if(mat[i][m-1] >= tar)
            {
                for(int j = m - 1; j >= 0; j--)
                {
                    if(mat[i][j] == tar)
                        return true;
                }
                break;
            }
        }
        return ans;
    }
};