class Solution {
public:
//     int nextGreaterElement(int n) 
//     {
//         // vector<int> v;
//         // long long x = n;
//         // while(x != 0)
//         // {
//         //     v.push_back(x % 10);
//         //     x = x / 10;
//         // }
//         // reverse(v.begin(), v.end());
//         // int flag = 0;
//         // for(int i = v.size() - 1; i >= 0; i--)
//         // {
//         //     int y = v[i];
//         //     int m = INT_MAX;
//         //     int ind = -1;
//         //     for(int j = i + 1; j < v.size(); j++)
//         //     {
//         //         if(v[j] > y && v[j] < m)
//         //         {
//         //             m = v[j];
//         //             ind = j;
//         //         }
//         //     }
//         //     if(m != INT_MAX)
//         //     {
//         //         v[i] = v[ind];
//         //         v[ind] = y;
//         //         flag = 1;
//         //         sort(v.begin() + i + 1, v.end());
//         //         break;
//         //     }
//         // }
//         // if(flag == 0)
//         // {
//         //     return -1;
//         // }
//         // long long ans = 0;
//         // x = 1;
//         // for(int i = v.size() - 1; i >= 0; i--)
//         // {
//         //     if(ans > INT_MAX || x > INT_MAX || ans < 0 || x < 0)
//         //     {
//         //         return -1;
//         //     }
//         //     ans = ans + (v[i] * x);
//         //     x = x * 10;
//         // }
//         // if(ans < 0)
//         // {
//         //     return -1;
//         // }
//         // return ans;
        
//     }
    bool nextPermutation(string& nums) {
        int i = nums.size()-1;
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        if (i == 0) return false;
        
        int j = nums.size()-1;
        while (j > 0 && nums[i-1]>=nums[j]) j--;
        swap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
    
    int nextGreaterElement(int n) {
        string num = to_string(n);
        bool res = nextPermutation(num);
        size_t ans = stoll(num);
        return (!res || ans > INT_MAX) ? -1 : ans;
    }
};