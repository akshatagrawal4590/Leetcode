//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(), wordList.end());
        us.erase(beginWord);
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        while(!q.empty()) {
            int n = q.size();
            
            while(n--) {
                
                vector<string>  front = q.front();
                q.pop();
                
                string s = front[front.size() - 1];
                
                if((s == targetWord) && (ans.empty() || ans[0].size() == front.size())) 
                        ans.push_back(front);
                
                
                for(int i=0; i<s.length(); i++) {
                    char orig = s[i];
                    for(char ch='a'; ch <= 'z'; ch++) {
                        s[i] = ch;
                        
                        if(us.find(s) != us.end()) {
                            front.push_back(s);
                            q.push(front);
                            temp.push_back(s);
                            front.pop_back();
                        }
                    }
                    s[i] = orig;
                }
                
            }
            
            for(auto it: temp)
                us.erase(it);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends