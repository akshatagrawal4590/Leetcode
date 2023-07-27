//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    pair<LNode*,LNode*> middleNode(LNode* head) 
    {
        LNode *slow=head,*fast=head,*prevtoslow=head;
        while(1)
        {
            if(fast==NULL)
            {
                break;
            }
            if(fast->next==NULL)
            {
                break;
            }
            prevtoslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return {prevtoslow,slow};
    }
    TNode* sortedListToBST(LNode *head) 
    {
        //Rare and Tortoise Algo + Merge Sort
        if(head==NULL)
        {
            return NULL;
        }
        pair<LNode*,LNode*>mid=middleNode(head);
        TNode* node=new TNode(mid.second->data);
        if(mid.second==head)
        {
            return node;
        }
        node->right=sortedListToBST(mid.second->next);
        mid.first->next=NULL;
        node->left=sortedListToBST(head);
        return node;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends