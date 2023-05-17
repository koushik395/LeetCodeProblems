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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode* curr = head, *prev = NULL;
        ListNode* next = curr->next;
        while(curr)
        {
            if(curr->val == val)
            {
                if(prev == NULL)
                    head = head->next;
                else
                {
                    prev->next = next;
                    curr->next = NULL;
                }
                curr = next;
                if(next!=NULL)
                next = next->next;
            }
            else
            {
                prev = curr;
                curr = next;
                if(next!=NULL)
                    next = next->next;   
            }
        }
        return head;
    }
};