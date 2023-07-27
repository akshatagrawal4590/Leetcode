//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool isPalindrome(string &s){
        int i=0;
        int j =s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    
    bool palindromepair(int n, string arr[]) 
    {
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++)
        {
            string s = arr[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < arr[i].length(); j++)
            {
                string s1 = arr[i].substr(0, j);
                string s2 = arr[i].substr(j);
                if(isPalindrome(s1) && mp.count(s2) && mp[s2] != i)
                {
                    return true;
                }
                if(isPalindrome(s2) && mp.count(s1) && mp[s1] != i)
                {
                    return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends