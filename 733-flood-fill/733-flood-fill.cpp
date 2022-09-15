class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)     {
        int n = image.size();
       
        int m = image[0].size();
         cout<<n<<m<<endl;
        int pixel = image[sr][sc];
        if(pixel == color)
            return image;
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        vector<vector<int>> visited(n, vector<int> (m, 0));
        q.push(make_pair(sr, sc));
        visited[sr][sc] = 1;
        int arr[] = {1, 0, -1, 0, 1};
        while(q.size() != 0)
        {
            int len = q.size();
            for(int it = 0; it < len; it++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                cout<<"gaamd"<<i<<" "<<j<<endl;
                for(int a = 0; a < 4; a++)
                {
                    int i1 = i + arr[a];
                    int j1 = j + arr[a+1];
                    cout<<i1<<" "<<j1<<"chumt ";
                    
                    if(i1>=0&&i1<n)
                    {
                        cout<<"a";
                        if(j1>=0&&j1<m)
                        {
                            cout<<"b";
                            if(image[i1][j1]==pixel)
                            {
                                cout<<"c";
                                if(!visited[i1][j1])
                                    {
                                    cout<<"d"<<endl<<i1<<" "<<j1<<endl;    
                                    image[i1][j1] = color;
                                    q.push(make_pair(i1, j1));
                                    visited[i1][j1] = 1;
                    }
                                    
                                
                            }
                        }
                    }
                
                }
            }
        }
        return image;
    }
};