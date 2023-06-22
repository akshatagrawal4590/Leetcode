class Solution {
public:
    int ladderLength(string sw, string tw, vector<string>& wl) 
    {
        queue <pair<string,int>> q;
        q.push({sw,1});
        unordered_set <string> st(wl.begin(),wl.end());
        if(st.find(tw) == st.end()) return 0;
        st.erase(sw);
        int n = sw.size();
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == tw) return steps;
            for(int i = 0; i < n; i++){
                char original = word[i];
                for(char ch = 'a' ;ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};