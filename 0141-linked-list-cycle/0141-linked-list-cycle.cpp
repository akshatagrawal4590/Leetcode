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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return false;
        }
        if(head -> next == NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int i = 0;
        while(slow != NULL && fast != NULL && fast -> next != NULL)
        {
            if(i != 0 && slow == fast)
            {
                return true;
            }
            i++;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};