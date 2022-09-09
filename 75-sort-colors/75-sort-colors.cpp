class Solution {
public:
    void sortColors(vector<int>& a) 
    {
        int n = a.size();
        int zerocount = 0;
        int onecount = 0;
        int twocount = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
                zerocount++;
            else if(a[i] == 1)
                onecount++;
            else
                twocount++;
        }
        for(int i = 0; i < n; i++)
        {
            if(zerocount != 0)
            {
                a[i] = 0;
                zerocount--;
            }
            else if(onecount != 0)
            {
                a[i] = 1;
                onecount--;
            }
            else
                a[i] = 2;
        }
    }
};