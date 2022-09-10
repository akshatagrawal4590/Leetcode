class Solution {
public:
    bool isValid(string x) 
    {
        stack<char> s;
        int i = 0;
        while(i < x.size())
        {
            if(x[i] == '[' || x[i] == '{' || x[i] == '(')
                s.push(x[i]);
            else
            {
                if(s.size() != 0 && s.top() == '[' && x[i] == ']')
                    s.pop();
                else if(s.size() != 0 && s.top() == '{' && x[i] == '}')
                    s.pop();
                else if(s.size() != 0 && s.top() == '(' && x[i] == ')')
                    s.pop();
                else
                    return false;
            }
            i++;
        }
        if(s.size() == 0)
            return true;
        else
            return false;    
    }
};