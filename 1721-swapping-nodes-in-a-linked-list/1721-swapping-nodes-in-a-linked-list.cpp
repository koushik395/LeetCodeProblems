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
    int countNodes(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int front = k;
        int back = countNodes(head) - k;
        ListNode* temp = head;
        ListNode* temp1,*temp2;
        int count = 1;
        while(temp!=NULL && count < front)
        {
            temp = temp->next;
            count++;
        } temp1 = temp;
        temp = head,count = 1;
        while(temp!=NULL && count <= back)
        {
            temp = temp->next;
            count++;
        } temp2 = temp;
        
        swap(temp1->val,temp2->val);
        return head;
    }
};