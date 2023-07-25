class Solution {
public:
    int f(vector<int> &v)
    {
        int ans = INT_MIN;
        int i = 0;
        int n = v.size();
        int j = n - 1;
        stack<int> s1;
        stack<int> s2;
        vector<int> ls(n, -1);
        vector<int> rs(n, -1);
        while(i < n)
        {
            if(i == 0 || j == n - 1)
            {
                ls[i] = 0;
                rs[j] = n - 1;
                s1.push(i);
                s2.push(j);
            }
            else
            {
                while(s1.size() != 0)
                {
                    if(v[s1.top()] < v[i])
                    {
                        ls[i] = s1.top() + 1;
                        s1.push(i);
                        break;
                    }
                    s1.pop();
                }
                if(s1.size() == 0)
                {
                    ls[i] = 0;
                    s1.push(i);
                }
                while(s2.size() != 0)
                {
                    if(v[s2.top()] < v[j])
                    {
                        rs[j] = s2.top() - 1;
                        s2.push(j);
                        break;
                    }
                    s2.pop();
                }
                if(s2.size() == 0)
                {
                    rs[j] = n - 1;
                    s2.push(j);
                }
            }
            i++;
            j--;
        }
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, v[i] * (rs[i] - ls[i] + 1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    v[j]++;
                }
                else
                {
                    v[j] = 0;
                }
                //cout<<v[j]<<" ";
            }
            //cout<<endl;
            ans = max(ans, f(v));
        }
        return ans;
    }
};