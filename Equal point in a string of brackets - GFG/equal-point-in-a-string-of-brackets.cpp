//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int findIndex(string str) 
    {
        int n = str.length();
        int i = 0;
        int j = n - 1;
        int c = 0;
        int o = 0;
        while(j >= 0)
        {
            if(str[j] == ')')
            {
                c++;
            }
            j--;
        }
        while(i < n)
        {
            if(o == c)
            {
                return i;
            }
            else
            {
                if(str[i] == '(')
                {
                    o++;
                }
                else
                {
                    c--;
                }
                i++;
            }
        }
        return i;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.findIndex(s)<<endl;
	}
}
// } Driver Code Ends