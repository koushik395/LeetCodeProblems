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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;

	if(list1 -> val <= list2 -> val)
	{
		list1 -> next = mergeTwoLists(list1 -> next, list2);
		return list1;
	}
	// we will call recursive l1 whole list and l2 -> next
	else
	{	
		list2 -> next = mergeTwoLists(list1, list2 -> next);
		return list2;            
	}
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        
        ListNode* head1 = lists[0];
        ListNode* head2 = lists[1];
        ListNode* mergedHead = mergeTwoLists(head1 , head2);
        
        for(int i= 2;i<lists.size();i++)
        {
            ListNode* nextHead = lists[i];
            mergedHead = mergeTwoLists(mergedHead,nextHead);
        }
        return mergedHead;
    }
};