//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // int arr[5] = {-1, 0, 1, 0, -1};
    
    // void bfs(int n, int m, vector<vector<int>> &visited, vector<vector<char>> &mat, int si, int sj)
    // {
    //     queue<pair<int, int>> q;
    //     q.push(make_pair(si, sj));
    //     while(q.size() != 0)
    //     {
    //         int x = q.front().first;
    //         int y = q.front().second;
    //         visited[x][y] = 1;
    //         q.pop();
    //         for(int ind = 0; ind < 4; ind++)
    //         {
    //             int i = x + arr[ind];
    //             int j = y + arr[ind+1];
    //             if(i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 'O' && visited[i][j] == 0)
    //             {
    //                 q.push(make_pair(i, j));
    //             }
    //         }
    //     }
    // }
    
    // vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    // {
    //     vector<vector<int>> visited(n, vector<int> (m, 0));
    //     int i = 0;
    //     int j = 0;
    //     while(j < m)
    //     {
    //         if(mat[i][j] == 'O' && visited[i][j] == 0)
    //         {
    //             bfs(n, m, visited, mat, i, j);
    //         }
    //         j++;
    //     }
    //     j--;
    //     i++;
    //     while(i < n)
    //     {
    //         if(mat[i][j] == 'O' && visited[i][j] == 0)
    //         {
    //             bfs(n, m, visited, mat, i, j);
    //         }
    //         i++;
    //     }
    //     i--;
    //     j--;
    //     while(j >= 0)
    //     {
    //         if(mat[i][j] == 'O' && visited[i][j] == 0)
    //         {
    //             bfs(n, m, visited, mat, i, j);
    //         }
    //         j--;
    //     }
    //     j++;
    //     i--;
    //     while(i >= 0)
    //     {
    //         if(mat[i][j] == 'O' && visited[i][j] == 0)
    //         {
    //             bfs(n, m, visited, mat, i, j);
    //         }
    //         i--;
    //     }
    //     for(int i = 0; i < n; i++)
    //     {
    //         for(int j = 0; j < m; j++)
    //         {
    //             if(visited[i][j] == 0 && mat[i][j] == 'O')
    //             {
    //                 mat[i][j] == 'X';
    //             }
    //         }
    //     }
    //     return mat;
    // }
    
        void bfs(vector<vector<char>>& mat , vector<vector<int>>& vis , int row , int col,
    int rowSize , int colSize){
        queue<pair<int,int>> q;
        q.push({row , col});
        vis[row][col] = 1;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r-1 >= 0 && mat[r-1][c] == 'O' && vis[r-1][c] == -1){
                q.push({r-1,c});
                vis[r-1][c] = 1;
            }
            
            if(c-1 >= 0 && mat[r][c-1] == 'O' && vis[r][c-1] == -1){
                q.push({r,c-1});
                vis[r][c-1] = 1;
            }
            
            if(r+1 < rowSize && mat[r+1][c] == 'O' && vis[r+1][c] == -1){
                q.push({r+1,c});
                vis[r+1][c] = 1;
            }
            
            if(c+1 < colSize && mat[r][c+1] == 'O' && vis[r][c+1] == -1){
                q.push({r,c+1});
                vis[r][c+1] = 1;
            }
        }
    }

    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n , vector<int> (m , -1));
        for(int i = 0 ; i < m ; i++){
            if(mat[0][i] == 'O' && vis[0][i] == -1){
                //dfs(mat , vis , 0 , i , n , m);
                bfs(mat , vis , 0 , i , n , m);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(mat[i][0] == 'O' && vis[i][0] == -1){
                //dfs(mat , vis , i , 0 , n , m);
                bfs(mat , vis , i , 0 , n , m);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(mat[i][m-1] == 'O' && vis[i][m-1] == -1){
                //dfs(mat , vis , i , m-1 , n , m);
                bfs(mat , vis , i , m-1 , n , m);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            if(mat[n-1][i] == 'O' && vis[n-1][i] == -1){
                //dfs(mat , vis , n-1 , i , n , m);
                bfs(mat , vis , n-1 , i , n , m);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'O' && vis[i][j] == -1){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends