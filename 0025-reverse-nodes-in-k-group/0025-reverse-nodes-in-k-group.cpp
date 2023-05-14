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
    // ListNode* reverseKGroup(ListNode* head, int k) 
    // {
    //     if(head == NULL || head -> next == NULL)
    //     {
    //         return head;
    //     }
    //     int x = 1;
    //     Node* temp = head;
    //     Node* newHead = NULL;
    //     Node* tail = NULL;
    //     Node* temp1 = NULL;
    //     Node* temp2 = NULL;
    //     while(temp != NULL)
    //     {
    //         if(x == 1)
    //         {
    //             temp1 = temp;
    //             x++;
    //             temp = temp -> next;
    //         }
    //         else if(x)
    //     }
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int cnt = 0;
        ListNode* counter = head;
        ListNode* temp = head;
        ListNode* ans = head;
        while(counter!=NULL){
            cnt++;
            counter = counter->next;
        }
        cnt /= k;
        stack<int> st;
        int k1 = k;

        while(temp!=NULL){
            st.push(temp->val);
            k1--;
            temp = temp->next;
            if(k1==0){
                while(!st.empty()){
                    ans->val = st.top();
                    st.pop();
                    ans = ans->next;
                }
                cnt--;
                k1 = k;
            }
            if(cnt==0){
                break;
            }
        }
        return head;
    }
};