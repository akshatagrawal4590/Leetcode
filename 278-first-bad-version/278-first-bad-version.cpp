// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long f(long long l, long long h)
    {
        if(l == h)
            return l;
        long long mid = (l + h) / 2;
        bool a = isBadVersion(mid);
        bool b = isBadVersion(mid + 1);
        if(a == false && b == true)
            return mid + 1;
        else if(a == true && b == true)
            return f(l, mid);
        else if(a == false && b == false)
            return f(mid + 1, h);
        return 0;
    }
    
    int firstBadVersion(int n) 
    {
        if(n == 1)
            return 1;
        return f(1, n);
    }
};