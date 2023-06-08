class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 0;
        int k = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(k < pairs[i][0])
            {
                ans++;
                k = pairs[i][1];
            }
        }
        return ans;
    }
};