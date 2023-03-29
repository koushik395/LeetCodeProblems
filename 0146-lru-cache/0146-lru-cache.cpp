class Node{

public:
	int key;
	int val;
	Node* next;
	Node* prev;

	Node(int key,int val)
	{
		this->key = key;
		this->val = val;
		this->prev = NULL;
		this->next = NULL;
	}
};

class LRUCache {
public:
    Node* head = NULL;
    Node* tail = NULL;
    unordered_map<int ,Node*> ans;
    int size;
	void insertAtHead(Node* &head,Node* &tail,int key,int val)
	{
		Node* newNode = new Node(key,val);
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else{
			newNode -> next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void deleteNode(Node* &head,Node* &tail,Node* address){ 
        if(head->next == NULL) {
            Node* temp = address;
            head = NULL;
            tail = NULL;
            delete temp;
        }
        else if(address == head) {
            Node* temp = head;
            temp -> next -> prev = NULL;
            head = temp ->next;
            temp -> next = NULL;
            delete temp;
        }   
        else{
            //deleting any middle node or last node
            Node* curr = address;
            Node* prev = curr->prev;

            curr -> prev = NULL;
            prev -> next = curr -> next;
            //last Node
            if(curr->next==NULL)
            {
                tail = prev;
            }//Middle Node
            else{
                curr->next->prev = prev;
                curr->next = NULL;
            }
            delete address;
        }
    }
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(ans.find(key)!=ans.end())
        {
        	Node* node = ans[key];
            int val = node -> val;
        	ans.erase(key);
        	deleteNode(head,tail,node);
        	insertAtHead(head,tail,key,val);
            ans[key] = head;
        	return head->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(ans.find(key)!=ans.end())
         {
            Node* existingNode = ans[key];
         	ans.erase(key);
         	deleteNode(head,tail,existingNode);
         }
         if(ans.size()==size)
         {
         	ans.erase(tail->key);
         	deleteNode(head,tail,tail);
         }
         insertAtHead(head,tail,key,value);
         ans[key] = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */