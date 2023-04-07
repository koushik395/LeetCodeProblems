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
    int ans = 0;
    int i =-1;
    // void reverse(ListNode* &head,ListNode* curr,ListNode* prev)
    // {
    //     if(curr==NULL)
    //     {
    //         head = prev;
    //         return;
    //     }
    //     ListNode* temp = curr->next;
    //     reverse(head,temp,curr);
    //     curr->next = prev;
    //     i++;
    //     ans = ans + curr->val * pow(2,i);
    // }
    int getDecimalValue(ListNode* head) {
        // ListNode* curr=head;
        // ListNode* prev = NULL;
        // reverse(head,curr,prev);
        // return ans;
        unsigned int ans = 0;
        while(head!=NULL)
        {
            ans <<= 1;
            ans = (ans | (head->val));
            head = head->next;
        }
        return ans;
    }
};