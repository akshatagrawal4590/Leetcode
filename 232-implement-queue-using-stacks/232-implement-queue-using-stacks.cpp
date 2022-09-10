class MyQueue {
public:
    stack<int> s1, s2;
    
    MyQueue() 
    {    
    }
    
    void push(int x) 
    {
        if(s2.size() == 0)
            s1.push(x);
        else
        {
            while(s2.size() != 0)
            {
                int x1 = s2.top();
                s2.pop();
                s1.push(x1);
            }
            s1.push(x);
        }    
    }
    
    int pop() 
    {
        if(s1.size() == 0 && s2.size() == 0)
            return -1;
        if(s1.size() == 0 && s2.size() != 0)
        {
            int ans = s2.top();
            s2.pop();
            return ans;
        }
        else if(s1.size() != 0 && s2.size() == 0)
        {
            while(s1.size() != 0)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            int ans = s2.top();
            s2.pop();
            return ans;
        }
        return 0;
    }
    
    int peek() 
    {
        if(s1.size() == 0 && s2.size() == 0)
            return -1;
        if(s1.size() == 0 && s2.size() != 0)
        {
            return s2.top();
        }
        else if(s1.size() != 0 && s2.size() == 0)
        {
            while(s1.size() != 0)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            return s2.top();
        }
        return 0;
    }
    
    bool empty() 
    {
        if(s1.size() == 0 && s2.size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */