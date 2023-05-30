//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str)
{
    int n = str.length();
    if(n == 1)
    {
        return str;
    }
    int i = 0;
    int j = n - 1;
    while(i < j)
    {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    return str;
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends