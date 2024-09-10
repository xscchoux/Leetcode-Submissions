class Node {
public:
    int val;
    Node *prev, *next;
    Node(int val): next(nullptr), prev(nullptr) {
        this->val = val;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node *head, *tail;
    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        Node* dummy = head;
        for (int i=0; i<=index; i++) {
            dummy = dummy->next;
        }
        return dummy->val; 
    }
    
    void addAtHead(int val) {
        size++;
        Node* nxt = head->next;
        Node* newNode = new Node(val);

        head->next = newNode;
        newNode->next = nxt;
        nxt->prev = newNode;
        newNode->prev = head;
    }
    
    void addAtTail(int val) {
        size++;
        Node* pre = tail->prev;
        Node* newNode = new Node(val);

        pre->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
        newNode->prev = pre;       
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        else if (index == size) {
            addAtTail(val);
        } else {
            Node* dummy = head;
            for (int i=0; i<=index; i++) {
                dummy = dummy->next;
            }
            Node* pre = dummy->prev;
            Node* newNode = new Node(val);
            pre->next = newNode;
            newNode->next = dummy;
            dummy->prev = newNode;
            newNode->prev = pre;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* dummy = head;
        for (int i=0; i<=index; i++) {
            dummy = dummy->next;
        }

        Node* pre = dummy->prev;
        Node* nxt = dummy->next;
        pre->next = nxt;
        nxt->prev = pre;
        size--;
        delete dummy;        
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