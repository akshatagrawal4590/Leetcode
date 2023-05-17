//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        if(dividend == divisor)
        {
            return 1;
        }
        unsigned long long a = abs(dividend);
        unsigned long long b = abs(divisor);
        long long ans = 0;
        while(a >= b)
        {
            int i = 0;
            unsigned long long temp;
            unsigned long long x = b;
            while(x <= a)
            {
                temp = x;
                x = x << 1;
                i++;
            }
            i--;
            a = a - temp;
            ans = ans + pow(2, i);
        }
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
        {
            return ans;
        }
        else
        {
            return -ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends