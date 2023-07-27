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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // base cases
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);

        // finding middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* Prev = NULL;

        while(fast && fast->next){
            Prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        // creating tree node & dividing list in two parts & recursive calls for leftSubList & rightsubList
        ListNode* Middle = slow;
        Prev->next = NULL;

        TreeNode* root = new TreeNode(Middle->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(Middle->next);

        // return answer 
        return root;
    }
};