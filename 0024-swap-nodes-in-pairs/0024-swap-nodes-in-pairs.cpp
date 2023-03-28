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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int k = 2;
        int cnt = 0;
        while(cnt < 2)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = head;
        head->next = NULL;
        
        if(curr!=NULL)
            head->next = swapPairs(curr);
        
        return prev;
    }
};