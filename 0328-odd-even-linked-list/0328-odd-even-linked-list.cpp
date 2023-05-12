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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        if(head -> next == NULL)
        {
            return head;
        }
        ListNode* os = NULL;
        ListNode* oe = NULL;
        ListNode* es = NULL;
        ListNode* ee = NULL;
        ListNode* temp = head;
        int count = 1;
        while(temp != NULL)
        {
            if(count % 2 != 0)
            {
                if(os == NULL)
                {
                    os = temp;
                    oe = temp;
                }
                else
                {
                    oe -> next = temp;
                    oe = temp;
                }
                temp = temp -> next;
                count++;
                continue;
            }
            if(count % 2 == 0)
            {
                if(es == NULL)
                {
                    es = temp;
                    ee = temp;
                }
                else
                {
                    ee -> next = temp;
                    ee = temp;
                }
                temp = temp -> next;
                count++;
                continue;
            }
        }
        oe -> next = es;
        ee -> next = NULL;
        return os;
        
    }
};