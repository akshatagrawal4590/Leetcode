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
    pair<ListNode*, ListNode*> f(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* temp1 = temp -> next;
        ListNode* tail = head;
        while(temp != NULL && temp1 != NULL)
        {
            ListNode* temp2 = temp1 -> next;
            temp1 -> next = temp;
            temp = temp1;
            temp1 = temp2;
        }
        tail -> next = NULL;
        return make_pair(temp, tail);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || head -> next == NULL || k == 1)
        {
            return head;
        }
        int x = 1;
        ListNode* temp = head;
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        ListNode* temp3 = NULL;
        while(temp != NULL)
        {
            if(x == 1)
            {
                temp1 = temp;
                x++;
                temp = temp -> next;
            }
            else if(x < k)
            {
                x++;
                temp = temp -> next;
            }
            else if(x == k)
            {
                temp2 = temp;
                temp = temp -> next;
                x = 1;
                temp2 -> next = NULL;
                pair<ListNode*, ListNode*> p1 = f(temp1);
                if(newHead == NULL)
                {
                    newHead = p1.first;
                    temp3 = p1.second;
                }
                else
                {
                    temp3 -> next = p1.first;
                    temp3 = p1.second;
                }
            }
        }
        if(temp3 != temp1)
        {
            temp3 -> next = temp1;   
        }
        return newHead;
    }
};