/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        temp = head; 
        
        while(temp!=NULL)
        {
            temp->next->random = temp->random ? temp->random->next:NULL;
            temp = temp->next->next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
        while (original && copy)
        {
            original->next =
             original->next? original->next->next : original->next;
     
            copy->next = copy->next?copy->next->next:copy->next;
            original = original->next;
            copy = copy->next;
        }

        // step 5 answer return
        return cloneHead;
    }
};