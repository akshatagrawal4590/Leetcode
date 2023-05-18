class Solution {
public:
    int countPrimes(int n) 
    {
        if(n == 1 || n == 0)
        {
            return 0;
        }
        vector<bool> isPrime(n, 1);
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(isPrime[i] == 1)
            {
                count++;
                int j = 2 * i;
                while(j < n)
                {
                    isPrime[j] = 0;
                    j = j + i;
                }
            }
        }
        return count;
    }
};