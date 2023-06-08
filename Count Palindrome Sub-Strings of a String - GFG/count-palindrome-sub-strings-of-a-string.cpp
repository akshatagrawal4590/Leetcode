//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char str[], int n)
{
    vector<vector<int>> dp(n, vector<int> (n, 0));
    int j = 0;
    int i = 0;
    while(j < n)
    {
        int k = j;
        while(k < n)
        {
            if(k == i)
            {
                dp[i][k] = 1;
            }
            else
            {
                if(str[i] == str[k])
                {
                    int x = i + 1;
                    int y = k - 1;
                    if(y >= x)
                    {
                        dp[i][k] = dp[x][y];
                    }
                    else
                    {
                        dp[i][k] = 1;
                    }
                }
            }
            i++;
            k++;
        }
        j++;
        i = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(dp[i][j] == 1 && i != j)
            {
                ans++;
            }
        }
    }
    return ans;   
}