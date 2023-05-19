class Solution {
public:
    int reverse(int x) 
    {
        if(x < 10 && x > -10)
        {
            return x;
        }
        long long a = pow(2, 31) - 1;
        long long b = pow(2, 31);
        if(x > 0)
        {
            long long i = 10;
            while(x / i != 0)
            {
                i = i * 10;
            }
            i = i / 10;
            long long ans = 0;
            while(x != 0)
            {
                long long y = x % 10;
                if(ans + (i * y) < a)
                {
                    ans = ans + (i * y);
                }
                else
                {
                    return 0;
                }
                x = x / 10;
                i = i / 10;
            }
            return ans;
        }
        long long i = 10;
        while(x / i != 0)
        {
            i = i * 10;
        }
        i = i / 10;
        long long ans = 0;
        while(x != 0)
        {
            long long y = -1 * (x % 10);
            if(ans + (i * y) < b)
            {
                ans = ans + (i * y);
            }
            else
            {
                return 0;
            }
            x = x / 10;
            i = i / 10;
        }
        return -1 * ans;
    }
};