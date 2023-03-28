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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* temp = curr;
        int count=0;
        
        while(temp!=NULL && count < k)
        {
            count++;
            temp = temp->next;
        }
        temp = curr;
        if(count==k)
        {
            count = 0;
            while(curr!=NULL && count<k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
        }
        else
            return temp;
        if(next!=NULL)
            head->next = reverseKGroup(next,k);
        
        return prev;
    }
};