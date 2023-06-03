//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    int n = s.length();
	    int x = 0;
	    for(int j = 0; j < n; j++)
	    {
	        if(s[j] == '1')
	        {
	            x++;
	        }
	    }
	    if(x == n)
	    {
	        return -1;
	    }
	    int i = 1;
	    int sum = 0;
	    int count = 0;
	    if(s[0] == '1')
	    {
	        sum = sum + 1;
	    }
	    else
	    {
	        sum = sum - 1;
	    }
	    count = sum;
	    while(i < n)
	    {
	        if(s[i] == '1')
	        {
	            if(count + 1 < 1)
	            {
	                count = count + 1;
	            }
	            else
	            {
	                count = 1;
	            }
	        }
	        else
	        {
	            if(count - 1 < -1)
	            {
	                count = count - 1;
	            }
	            else
	            {
	                count = -1;
	            }
	        }
	        sum = min(sum, count);
	        i++;
	    }
	    if(sum < 0)
	    {
	        return sum * -1;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends