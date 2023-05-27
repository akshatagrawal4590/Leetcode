class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        int r = mat.size();
        int c = mat[0].size();
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