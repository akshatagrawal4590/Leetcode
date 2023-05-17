class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        if(start == goal)
        {
            return 0;
        }
        int x = start ^ goal;
        int ans = 0;
        while(x != 0)
        {
            int y = x & 1;
            if(y == 1)
            {
                ans++;
            }
            x = x >> 1;
        }
        return ans;
    }
};