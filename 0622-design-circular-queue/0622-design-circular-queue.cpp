class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        if (front == (rear + 1) % size) {
            front = -1;
            rear = -1;
        }
        return true;
    }

    int Front() {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    int Rear() {
        if (rear == -1) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return front == (rear + 1) % size;
    }
};



/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */