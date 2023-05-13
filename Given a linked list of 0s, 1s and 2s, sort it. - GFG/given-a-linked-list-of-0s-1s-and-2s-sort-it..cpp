//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        Node* temp = head;
        Node* zs = NULL;
        Node* ze = NULL;
        Node* os = NULL;
        Node* oe = NULL;
        Node* ts = NULL;
        Node* te = NULL;
        while(temp != NULL)
        {
            if(temp -> data == 2)
            {
                if(ts == NULL)
                {
                    ts = temp;
                    te = ts;
                }
                else
                {
                    te -> next = temp;
                    te = temp;
                }
            }
            if(temp -> data == 1)
            {
                if(os == NULL)
                {
                    os = temp;
                    oe = os;
                }
                else
                {
                    oe -> next = temp;
                    oe = temp;
                }
            }
            if(temp -> data == 0)
            {
                if(zs == NULL)
                {
                    zs = temp;
                    ze = zs;
                }
                else
                {
                    ze -> next = temp;
                    ze = temp;
                }
            }
            temp = temp -> next;
        }
        if(zs != NULL)
        {
            if(os != NULL)
            {
                if(ts != NULL)
                {
                    ze -> next = os;
                    oe -> next = ts;
                    te -> next = NULL;
                    return zs;
                }
                else
                {
                    ze -> next = os;
                    oe -> next = NULL;
                    return zs;
                }
            }
            else
            {
                if(ts != NULL)
                {
                    ze -> next = ts;
                    te -> next = NULL;
                    return zs;
                }
                else
                {
                    return head;
                }
            }
        }
        else
        {
            if(os != NULL)
            {
                if(ts != NULL)
                {
                    oe -> next = ts;
                    te -> next = NULL;
                    return os;
                }
                else
                {
                    return head;
                }
            }
            else
            {
                return head;
            }
        }
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends