class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            if(m.count(arr[i]) == 0)
            {
                m[arr[i]] = 1;
            }
        }
        int i = 0;
        int ans = 0;
        while(i < n)
        {
            int x = arr[i];
            if(m.count(x-1) > 0)
            {
                i++;
            }
            else
            {
                int count = 1;
                int j = 1;
                while(m.count(x+j) > 0)
                {
                    count++;
                    j++;
                }
                ans = max(ans, count);
                i++;
            }
        }
        return ans;
    }
};