// class Solution {
// public:
//     int f(vector<vector<char>> &board, string s, vector<vector<int>> &visited, int a, int b, int n, int m)
//     {
//         if(s.length() == 0)
//         {
//             return 1;
//         }
//         int arr[] = {-1, 0, 1, 0, -1};
//         for(int i = 0; i < 4; i++)
//         {
//             int x = a + arr[i];
//             int y = b + arr[i+1];
//             if(x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0 && board[x][y] == s[0])
//             {
//                 visited[x][y] = 1;
//                 int ans = f(board, s.substr(1), visited, x, y, n, m);
//                 if(ans == 1)
//                 {
//                     return 1;
//                 }
//             }
//         }
//         return 0;
//     }
    
//     bool exist(vector<vector<char>>& board, string word) 
//     {
//         int n = board.size();
//         int m = board[0].size();
//         cout<<n<<" "<<m;

//         for(int i = 0; i < n; i ++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(board[i][j] == word[0])
//                 {
//                     vector<vector<int>> visited(n, vector<int> (m, 0));
//                     visited[i][j] = 1;
//                     int ans = f(board, word.substr(1), visited, i, j, n, m);
//                     if(ans == 1)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;    
//     }
// };

class Solution {
public:
bool search(vector<vector<char>> &b, string w,int r,int c){
    
    if(w.empty()){
        return true;
    }
    
    char val=b[r][c];
    b[r][c]='*';
    char ch=w[0];
    bool dis=false;
    if(r>0){
        if(b[r-1][c]==ch){
           
            dis=dis||search(b,w.substr(1),r-1,c);
    
          
        }
    }
    if(c>0){
        if(b[r][c-1]==ch){
            
            dis=dis||search(b,w.substr(1),r,c-1);
           
        }
    }
    if(r<b.size()-1){
        if(b[r+1][c]==ch){
            dis=dis||search(b,w.substr(1),r+1,c);
            
        }
    }
    if(c<b[0].size()-1){
        if(b[r][c+1]==ch){
            dis=dis||search(b,w.substr(1),r,c+1);
          
        }
    }
   b[r][c]=val;
    return dis;
}
    bool exist(vector<vector<char>>& b, string w) {
        vector<vector<int>> start;
        
        vector<vector<int>> cord;
       
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                if(b[i][j]==w[0]){
                    cord.push_back({i,j});

                }
                
                
            }
        }
        
        for(auto v:cord){
            if(search(b,w.substr(1),v[0],v[1]))return true;
            
        }

        return false;}
};