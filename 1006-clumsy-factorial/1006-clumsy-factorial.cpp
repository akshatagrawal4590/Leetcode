class Solution {
public:
    int clumsy(int n) 
    {
        if(n == 1 || n == 2)
        {
            return n;
        }
        if(n == 3)
        {
            return 6;
        }
        int ans = 0;
        int i = n;
        while(i > 0)
        {
            if(i == n)
            {
                ans = ans + ((i * (i - 1)) / (i - 2)) + i - 3;
                i = i - 4;
            }
            else
            {
                if(i - 3 > 0)
                {
                    ans = ans - ((i * (i - 1)) / (i - 2)) + i - 3;
                    i = i - 4;
                }
                else
                {
                    if(i == 1)
                    {
                        ans = ans - 1;
                        break;
                    }
                    else if(i == 2)
                    {
                        ans = ans - 2;
                        break;
                    }
                    else
                    {
                        ans = ans - 6;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};