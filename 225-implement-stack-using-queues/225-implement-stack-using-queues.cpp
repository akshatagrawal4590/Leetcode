class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        if(q1.size() == 0)
        {
            q1.push(x);
            if(q2.size() != 0)
            {
                while(q2.size() != 0)
                {
                    int x = q2.front();
                    q2.pop();
                    q1.push(x);
                }
            }
        }
        else
        {  
            q2.push(x);
            if(q1.size() != 0)
            {
                while(q1.size() != 0)
                {
                    int x = q1.front();
                    q1.pop();
                    q2.push(x);
                }
            }
        }
    }
    
    int pop() 
    {
        if(q1.size() != 0)
        {
            int x = q1.front();
            q1.pop();
            return x;
        }
        else if(q2.size() != 0)
        {
            int x = q2.front();
            q2.pop();
            return x;
        }
        else
            return -1;
    }
    
    int top() 
    {
        if(q1.size() != 0)
            return q1.front();
        else if(q2.size() != 0)
            return q2.front();
        else
            return -1;
    }
    
    bool empty() 
    {
        if(q1.size() == 0 && q2.size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */