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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int n, Node *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp -> data % 2 == 0)
            {
                if(evenStart == NULL)
                {
                    evenStart = temp;
                    evenEnd = temp;
                }
                else
                {
                    evenEnd -> next = temp;
                    evenEnd = temp;
                }
                temp = temp -> next;
                continue;
            }
            if(temp -> data % 2 != 0)
            {
                if(oddStart == NULL)
                {
                    oddStart = temp;
                    oddEnd = temp;
                }
                else
                {
                    oddEnd -> next = temp;
                    oddEnd = temp;
                }
                temp = temp -> next;
                continue;
            }
        }
        if(evenEnd != NULL && evenStart != NULL)
        {
            if(oddStart != NULL && oddEnd != NULL)
            {
                evenEnd -> next = oddStart;
                oddEnd -> next = NULL;
                return evenStart;
            }
            return evenStart;
        }
        return oddStart;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends