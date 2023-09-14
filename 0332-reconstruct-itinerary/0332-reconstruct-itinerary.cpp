class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
        for(auto it:tickets)
        {
            mp[it[0]].push(it[1]);         
        }
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while(!st.empty())
        {
            string curr=st.top();
            if(mp.find(curr)!=mp.end() && !mp[curr].empty())
            {
                st.push(mp[curr].top());
                mp[curr].pop();
            }
            else
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};