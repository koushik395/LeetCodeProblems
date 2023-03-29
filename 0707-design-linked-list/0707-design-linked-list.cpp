class Node{

public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


class MyLinkedList {
public:
    Node* head;
    Node* tail;
    MyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    
    int get(int index) {
        Node* temp = head;
        if(temp==NULL)
            return -1;
        int cnt = 0;
        while(cnt < index)
        {
            temp = temp -> next;
            if(temp==NULL)
                return -1;
            cnt++;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        if(temp == NULL)
            return;
        int cnt = 0;
        while(cnt < index - 1)
        {
            temp = temp -> next;
            if(temp==NULL)
                return;
            cnt++;
        }
        if(temp->next == NULL)
        {
            addAtTail(val);
            return;
        }
        newNode -> next = temp -> next;
        temp ->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        //deleting first or start node
        if(index == 0) {
            Node* temp = head;
            head = head -> next;
            //memory free start node
            temp -> next = NULL;
            delete temp;
        }
        else
        {
            //deleting any middle node or last node
            Node* curr = head;
            Node* prev = NULL;

            int cnt = 0;
            while(cnt < index) {
                prev = curr;
                curr = curr -> next;
                if(curr == NULL)
                    return;
                cnt++;
            }

            if(curr->next==NULL)
            {
                tail = prev;
            }
            prev -> next = curr -> next;
            curr -> next  = NULL;
            delete curr;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */