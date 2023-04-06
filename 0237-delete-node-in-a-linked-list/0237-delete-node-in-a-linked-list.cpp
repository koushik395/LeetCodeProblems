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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* next = curr->next;
        while(next!=NULL)
        {
            curr->val = next->val;
            if(next->next == NULL)
                curr->next = NULL;
            curr = next;
            next = next->next;
        }
    }
};