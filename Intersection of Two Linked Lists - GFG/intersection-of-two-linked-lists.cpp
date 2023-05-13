//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int, int> m;
        Node* temp = head2;
        while(temp != NULL)
        {
            m[temp -> data] = 1;
            temp = temp -> next;
        }
        if(head1 == NULL || m.size() == 0)
        {
            return NULL;
        }
        temp = head1;
        Node* newHead = NULL;
        Node* tail = NULL;
        while(temp != NULL)
        {
            if(m.count(temp -> data)> 0)
            {
                if(newHead == NULL)
                {
                    newHead = temp;
                    tail = temp;
                }
                else
                {
                    tail -> next = temp;
                    tail = temp;
                }
            }
            temp = temp -> next;
        }
        tail -> next = NULL;
        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends