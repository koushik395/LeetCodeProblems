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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow, slow = slow->next, prev->next = NULL;
        while(slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head, slow = prev;
        int maxVal = 0;
        while (slow)
        {
            int sum = fast->val + slow->val;
            maxVal = max(maxVal,sum);
            slow = slow->next,fast = fast->next;
        }
        return maxVal;
    }
};