class Solution {
public:
    int f(int l, int r, vector<int> &arr)
    {
        if(l < r)
        {
            int mid = (l + r) / 2;
            if(mid == l)
            {
                return min(arr[mid], f(mid + 1, r, arr));   
            }
            else
            {
                if(arr[mid] < arr[mid-1])
                {
                    return arr[mid];
                }
                else
                {
                    int x = f(l, mid - 1, arr);
                    int y = f(mid + 1, r, arr);
                    return min(x, y);
                }
            }
        }
        return arr[l];
    }
    
    int findMin(vector<int>& arr) 
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        return f(l, r, arr);
    }
};