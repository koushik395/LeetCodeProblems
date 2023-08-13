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
    int carry;
    void solve(ListNode* &head,ListNode* curr,ListNode* prev)
    {
        if(curr==NULL)
        {
            return;
        }
        ListNode* temp = curr->next;
        
        solve(head,temp,curr);
        
        int sum = curr->val + curr->val + carry;
        curr->val = sum % 10;
        carry = sum / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        carry = 0;
        solve(head,head,NULL);
        if(carry)
        {
            ListNode* newhead = new ListNode(carry);
            newhead->next = head;
            head = newhead;
        }
        return head;
    }
};