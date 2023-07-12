//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        sort(words.begin(), words.end());
        int n = words.size();
        unordered_map<string, int> m;
        int x = INT_MIN;
        string s = "";
        for(int i = 0; i < n; i++)
        {
            if(m.count(words[i]) == 0)
            {
                m[words[i]] = 1;
            }
            int j = 0;
            int y = words[i].length();
            while(j < y)
            {
                string s1 = words[i].substr(0, j + 1);
                if(m.count(s1) > 0)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            if(j == y)
            {
                if(y > x)
                {
                    x = y;
                    s = words[i];
                }
            }
        }
        if(x == INT_MIN)
        {
            return "";    
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends