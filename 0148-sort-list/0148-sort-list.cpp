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
    ListNode* join(ListNode* head1, ListNode* head2)
    {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> val < head2 -> val)
            {
                if(head == NULL)
                {
                    head = head1;
                    temp = head;
                }
                else
                {
                    temp -> next = head1;
                    temp = head1;
                }
                head1 = head1 -> next;
            }
            else
            {
                if(head == NULL)
                {
                    head = head2;
                    temp = head;
                }
                else
                {
                    temp -> next = head2;
                    temp = head2;
                }
                head2 = head2 -> next;
            }
        }
        if(head1 != NULL)
        {
            temp -> next = head1;
        }
        if(head2 != NULL)
        {
            temp -> next = head2;
        }
        return head;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* superSlow = NULL;
        while(fast != NULL && fast -> next != NULL)
        {
            superSlow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        superSlow -> next = NULL;
        ListNode* temp1 = sortList(head);
        ListNode* temp2 = sortList(slow);
        return join(temp1, temp2);
    }
};