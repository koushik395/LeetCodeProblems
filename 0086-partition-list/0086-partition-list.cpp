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
    ListNode* partition(ListNode* head, int x) {
        ListNode* nod1 = new ListNode(0);
        ListNode* nod2 = new ListNode(0);
        ListNode* p1 = nod1,*p2 = nod2;
        while(head)
        {
            if(head->val < x)
            {
                p1 = p1 -> next = head;
            }
            else
            {
                p2 = p2 -> next = head;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = nod2->next;
        return nod1->next;
    }
};