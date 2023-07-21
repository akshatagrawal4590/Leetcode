//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int> ans;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](const pair<int, int>& a, const pair<int, int>& b) {
        // if (a.first != b.first) {
        //     return a.first > b.first;  // ">" to sort in descending order of the first element
        // } else {
        //     return a.second < b.second; // "<" to sort in ascending order of the second element
        // }})> pq;
        priority_queue<pair<int, int>> pq;
        int i = 0;
        int j = 0;
        while(j < k)
        {
            pq.push({arr[j], j});
            j++;
        }
        ans.push_back(pq.top().first);
        while(j < n)
        {
            pq.push({arr[j], j});
            i++;
            while(pq.top().second < i)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);        
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends