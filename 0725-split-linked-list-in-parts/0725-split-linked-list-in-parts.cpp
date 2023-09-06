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
    int getlength(ListNode* head)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        int N = getlength(head);
        int eachPart = N / k;
        int extra = N % k;
        int i = 0;
        
        while(head!= NULL)
        {
            ans[i++] =  head;
            int cnt = (extra!=0) ? eachPart + 1:eachPart;
            if(extra > 0) extra--;
            
            while(head != NULL && --cnt)
            {
                head = head->next;
            }
            ListNode* temp = head->next;
            if(head!=NULL) head->next = NULL;
            head = temp;
        }
        return ans;
    }
};