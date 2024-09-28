class MyCircularDeque {
private:
    deque<int> dq;
    int k, size;
public:
    MyCircularDeque(int k) {
        this->k = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (size < k) {
            dq.push_front(value);
            size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (size < k) {
            dq.push_back(value);
            size++;
            return true;
        }
        return false;        
    }
    
    bool deleteFront() {
        if (size > 0) {
            dq.pop_front();
            size--;
            return true;
        }
        return false;            
    }
    
    bool deleteLast() {
        if (size > 0) {
            dq.pop_back();
            size--;
            return true;
        }
        return false;          
    }
    
    int getFront() {
        return (size>0)?dq.front():-1;      
    }
    
    int getRear() {
        return (size>0)?dq.back():-1;       
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};



// Fixed Array with Circular Ordering
class MyCircularDeque {
private:
    vector<int> arr;
    int front, tail, size, k;
public:
    MyCircularDeque(int k) {
        this->k = k;
        arr.resize(k, -1);
        front = 0;
        tail = k-1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front-1+k)%k;
        arr[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        tail = (tail+1+k)%k;
        arr[tail] = value;
        size++;
        return true;        
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front+1+k)%k;
        size--;
        return true;        
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail-1+k)%k;
        size--;
        return true;            
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[tail];        
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */