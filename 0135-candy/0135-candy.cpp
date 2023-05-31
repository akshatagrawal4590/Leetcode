class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        if(n == 1)
        {
            return 1;
        }
        vector<int> v(n, 1);
        int i = 0;
        int j = 1;
        while(j < n)
        {
            if(ratings[i] < ratings[j])
            {
                if(v[j] > v[i])
                {
                    i++;
                    j++;
                    continue;
                }
                v[j] = v[i] + 1;
            }
            i++;
            j++;
        }
        i = n - 1;
        j = n - 2;
        while(j >= 0)
        {
            if(ratings[j] > ratings[i])
            {
                if(v[j] > v[i])
                {
                    j--;
                    i--;
                    continue;
                }
                v[j] = v[i] + 1;
            }
            i--;
            j--;
        }
        int ans = 0;
        for(int k = 0; k < n; k++)
        {
            ans = ans + v[k];
        }
        return ans;
    }
};