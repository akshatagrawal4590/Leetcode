//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    struct Node* reverse(struct Node* head)
    {
        if(head -> next == NULL)
        {
            return head;
        }
        Node* temp = head;
        Node* temp1 = head -> next;
        temp -> next = NULL;
        while(temp1 != NULL)
        {
            Node* temp2 = temp1 -> next;
            temp1 -> next = temp;
            temp = temp1;
            temp1 = temp2;
        }
        return temp;
    }
    
    struct Node* modifyTheList(struct Node *head)
    {
        if(head -> next == NULL)
        {
            return head;
        }
        if(head -> next -> next == NULL)
        {
            int x = head -> data;
            head -> data = head -> next -> data - x;
            head -> next -> data = x;
            return head;
        }
        Node* superSlow = head;
        Node* slow = head;
        Node* fast = head;
        int c = 0;
        while(fast != NULL && fast -> next != NULL)
        {
            if(c != 0)
            {
                superSlow = superSlow -> next;
            }
            c++;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast == NULL)
        {
            Node* temp = reverse(superSlow -> next);
            superSlow -> next = temp;
            slow = head;
            while(temp != NULL)
            {
                int x = slow -> data;
                slow -> data = temp -> data - slow -> data;
                temp -> data = x;
                slow = slow -> next;
                temp = temp -> next;
            }
            superSlow -> next = reverse(superSlow -> next);
            return head;
        }
        else
        {
            Node* temp = reverse(slow -> next);
            slow -> next = temp;
            fast = head;
            while(temp != NULL)
            {
                int x = fast -> data;
                fast -> data = temp -> data - fast -> data;
                temp -> data = x;
                fast = fast -> next;
                temp = temp -> next;
            }
            slow -> next = reverse(slow -> next);
            return head;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends