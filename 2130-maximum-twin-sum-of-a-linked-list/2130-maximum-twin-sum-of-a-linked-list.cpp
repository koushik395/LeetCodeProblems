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
        vector<int> nodes;
        for(ListNode* i = head;i!=nullptr;i = i -> next)
        {
            nodes.push_back(i->val);
        }
        int n = nodes.size(),maxVal = 0;
        for(int i=0;i<n/2;i++)
        {
            int sum = nodes[i] + nodes[n-1-i];
            maxVal = max(maxVal,sum);
        }
        return maxVal;
    }
};