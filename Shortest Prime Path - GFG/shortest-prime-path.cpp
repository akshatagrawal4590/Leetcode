//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
     int solve(int num1,int num2)
   {   
     //code here
      int n =10000;
        vector<bool> isPrime(n,1);
isPrime[0]= false;
isPrime[1]=false;
for(int i=2;i<n;i++){
   if(isPrime[i]==true){
       for(int j=2*i;j<n;j+=i){
           isPrime[j]=false;
       }
   }
}
if(num1==num2) return 0;
vector<int> vis(n,0);
queue<int> q;
q.push(num1);
vis[num1]=1;
int count=0;
while(!q.empty()){
   int n = q.size();
   for(int itr=0;itr<n;itr++){
       int temp=q.front();
       q.pop();
   for(int i=0;i<4;i++){
       for(int j=0;j<10;j++){
           if(j==0 && i==0) continue;

 

          //Converting number into string
           string str= to_string(temp);

 

         //Converting int to char
           str[i] = j+ '0';

 

         //Converting string to int
           int num = stoi(str);


           if(num==num2) return count+1;
           if(vis[num] || !isPrime[num]) continue;
           vis[num]=1;
           q.push(num);
       }
   }  
   }
   count++;
}
return count;
   }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends