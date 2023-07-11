//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int arr[5] = {-1, 0, 1, 0, -1};
    
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c)
    {
        int i = 0;
        int j = 0;
        int ind = 1;
        while(i < r && i >= 0 && j < c && j >= 0)
        {
            //cout<<i<<" "<<j<<endl;
            if(matrix[i][j] == 0)
            {
                i = i + arr[ind];
                j = j + arr[ind+1];
            }
            else
            {
                matrix[i][j] = 0;
                ind++;
                if(ind == 4)
                {
                    ind = 0;
                }
                i = i + arr[ind];
                j = j + arr[ind+1];
            }
        }
        return make_pair(i - arr[ind], j - arr[ind+1]);
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends