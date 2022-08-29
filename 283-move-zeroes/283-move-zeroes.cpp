class Solution {
public:
    void moveZeroes(vector<int>& arr) 
    {
        int n = arr.size();
        int i = 0;
	    int j = 0;
	    //int zerocount = 0;
	    while(j < n)
	    {
	        if(arr[j] != 0)
	        {
	            i++;
	            j++;
	        }
	        else
	        {
	            //zerocount++;
	            j++;
	            while(j < n)
	            {
	                if(arr[j] == 0)
	                {
	                    //zerocount++;
	                    j++;
	                }
	                else
	                {
	                    arr[i] = arr[j];
	                    i++;
	                    j++;
	                }
	            }
	            break;
	        }
	    }
	    while(i < n)
	    {
	        arr[i] = 0;
	        i++;
	    }
    }
};