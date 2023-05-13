//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
     Node *reverse(Node *h){
        
        Node *curr = h;
        Node *nxt = NULL;
        Node *temp;
        
        while(curr!=NULL){
            temp = curr->next;
            curr->next = nxt;
            nxt = curr;
            curr = temp;
        }
        
        return nxt;
    }
    
    public:
    Node* addOne(Node *head) 
    {
       Node *i = reverse(head);
       Node *res = i;
       int carry = 1;
       
       Node *prev;
       
       //Adding 1 to the numbers for all possible cases
       
       while(i!=NULL){
           
           if(i->data < 9 && carry  == 1){
               i->data = i->data + carry;
               carry = 0;
           }
           
           if(i->data == 9 && carry == 1){
               i->data = 0;
               carry = 1;
           }
           
           prev = i;
           i = i->next;
       }
       
       if(carry == 1){
           Node *last = new Node(carry);
           prev->next = last;
       }
       
       //reversing again to get the desired result
       return reverse(res);
     
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends