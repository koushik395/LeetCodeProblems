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
    int getLength(ListNode* &head)
    {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int len = getLength(head);
        int cnt = 1;
        k = k%len;
        while(cnt <= len-k)
        {
            prev = curr;
            curr = curr -> next;
            if(curr==NULL)
            {
                prev = curr;
                curr = head;
            }
            cnt++;
        }
        if(prev!=NULL)
        {
            prev->next = NULL;
            ListNode* temp = curr;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = head;
            head = curr;
        }
        return head;
    }
};