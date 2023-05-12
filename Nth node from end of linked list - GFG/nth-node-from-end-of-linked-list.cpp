//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    if(head == NULL)
    {
        return -1;
    }
    if(head -> next == NULL)
    {
        if(n == 1)
        {
            return head -> data;
        }
        else
        {
            return -1;
        }
    }
    Node* temp = head;
    int l = 0;
    Node* temp1 = temp -> next;
    while(temp != NULL && temp1 != NULL)
    {
        Node* temp2 = temp1 -> next;
        temp1 -> next = temp;
        temp = temp1;
        temp1 = temp2;
        if(temp1 == NULL)
        {
            l = l + 2;
        }
        else
        {
            l = l + 1;
        }
    }
    if(n > l)
    {
        return -1;
    }
    if(n == 1)
    {
        return temp -> data;
    }
    while(n != 1)
    {
        temp = temp -> next;
        n--;
    }
    return temp -> data;
}

