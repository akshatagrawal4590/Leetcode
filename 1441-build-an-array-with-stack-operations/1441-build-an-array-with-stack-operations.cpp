class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        //stack<int> s;
        int i = 1;
        int len = target.size();
        int j = 0;
        while(i <= n && j < len)
        {
            if(i == target[j])
            {
                //s.push(i);
                j++;
                i++;
                ans.push_back("Push");
            }
            else
            {
                //s.push(i);
                ans.push_back("Push");
                //s.pop();
                ans.push_back("Pop");
                i++;
            }
        }
        return ans;
    }
};