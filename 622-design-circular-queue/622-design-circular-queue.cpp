class MyCircularQueue {
    vector<int>arr;
    int frontIdx,size,capacity;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        frontIdx=0;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int val) {
        if(isFull()) return false;
        arr[(frontIdx+size)%capacity]=val;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        frontIdx=(frontIdx+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[frontIdx];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[(frontIdx+size-1)%capacity];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
     return size==capacity;   
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