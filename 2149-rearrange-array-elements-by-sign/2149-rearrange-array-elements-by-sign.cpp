class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, int> pos;
	    unordered_map<int, int> neg;
	    int i = 1;
	    int j = 1;
	    int k = 0;
	    while(k < n)
	    {
	        if(arr[k] >= 0)
	        {
	            pos[i] = arr[k];
	            i++;
	        }
	        else
	        {
	            neg[j] = arr[k];
	            j++;
	        }
	        k++;
	    }
	    if(i == 1 || j == 1)
	    {
	        return arr;
	    }
	    k = 0;
	    int flag = 0;
	    i = 1;
	    j = 1;
	    while(k < n)
	    {
	        if(flag == 0)
	        {
	            if(pos.count(i) > 0)
	            {
	                arr[k] = pos[i];
        	        i++;
        	        flag = 1;
        	        k++;
        	        continue;
	            }
	            else
	            {
	                break;
	            }
	        }
	        if(flag == 1)
	        {
	            if(neg.count(j) > 0)
	            {
	                arr[k] = neg[j];
	                j++;
	                flag = 0;
	                k++;
	                continue;
	            }
	            else
	            {
	                break;
	            }
	        }
	    }
	    if(k == n)
	    {
	        return arr;
	    }
	    if(pos.count(i) == 0)
	    {
	        while(k < n)
	        {
	            arr[k] = neg[j];
	            j++;
	            k++;
	        }
	    }
	    if(neg.count(j) == 0)
	    {
	        while(k < n)
	        {
	            arr[k] = pos[i];
	            i++;
	            k++;
	        }
	    }
	    return arr;
    }
};