/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head -> next == NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int l = 0;
        while(fast != NULL && fast -> next != NULL)
        {
            l = l + 2;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast == NULL)
        {
            int x = l - n + 1;
            int s = (l / 2) + 1;
            //cout<<l<<" "<<x<<" "<<s<<endl;
            if(x > s)
            {
                while(s < x - 1)
                {
                    slow = slow -> next;
                    s++;
                }
                ListNode* temp = slow -> next -> next;
                slow -> next = temp;
                return head;
            }
            else
            {
                if(x == 1)
                {
                    return head -> next;
                }
                ListNode* temp = head;
                while(x > 2)
                {
                    temp = temp -> next;
                    x--;
                }
                ListNode* temp1 = temp -> next -> next;
                temp -> next = temp1;
                return head;
            }
        }
        l = l + 1;
        int x = l - n + 1;
        int s = (l / 2) + 1;
        if(x > s)
        {
            while(s < x - 1)
            {
                slow = slow -> next;
                s++;
            }
            ListNode* temp = slow -> next -> next;
            slow -> next = temp;
            return head;
        }
        if(x == 1)
        {
            return head -> next;
        }
        ListNode* temp = head;
        while(x > 2)
        {
            temp = temp -> next;
            x--;
        }
        ListNode* temp1 = temp -> next -> next;
        temp -> next = temp1;
        return head;
    }
};