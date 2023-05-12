/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp -> val = 1e8;
            if(temp -> next != NULL)
            {
                if(temp -> next -> val == 1e8)
                {
                    return temp -> next;
                }
                temp = temp -> next;
            }
            else
            {
                return NULL;
            }
        }
        return NULL;
    }
};