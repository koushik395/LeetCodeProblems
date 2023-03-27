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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        if(head==NULL)
            return ans;
        int row = m;
        int col = n;
        int total = row*col;
        int startrow = 0;
        int startcol = 0;
        int endrow = row-1;
        int endcol = col-1;

        int count = 0;
        while(count < total && head!=NULL){
            for(int index = startcol;count<total && index <= endcol && head!=NULL ;index++)
            {
                ans[startrow][index] = head->val;
                head = head->next;
                count++;
            }
            startrow++;
            for(int index = startrow;count<total && index <= endrow && head!=NULL; index++)
            {
                ans[index][endcol] = head->val;
                head = head -> next;
                count++;
            }
            endcol--;
            for(int index = endcol;count<total && index >= startcol && head!=NULL; index--)
            {
                ans[endrow][index] = head->val;
                head = head -> next;
                count++;
            }
            endrow--;
            for(int index = endrow;count<total && index >= startrow && head!=NULL; index--)
            {
                ans[index][startcol] = head->val;
                head = head->next;
                count++;
            }
            startcol++;
        }
        
        return ans;
        
    }
};