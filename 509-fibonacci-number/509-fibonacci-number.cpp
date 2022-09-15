class Solution {
public:
    int f(vector<int> &v, int n, int i)
    {
        if(i == 0)
            return 0;
        if(i == 1)
            return 1;
        if(v[i] != -1)
            return v[i];
        int x = f(v, n, i - 1);
        int y = f(v, n, i - 2);
        v[i] = x + y;
        return v[i];
    }
    
    int fib(int n) 
    {
        vector<int> v(n + 1, -1);
        return f(v, n, n);
    }
};