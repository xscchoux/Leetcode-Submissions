class CustomStack {
private:
    vector<int> stk, incArr;
    int topInd;
public:
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        incArr.resize(maxSize);
        topInd = -1;
    }
    
    void push(int x) {
        if (topInd + 1 < stk.size()) {
            stk[++topInd] = x;
        }
    }
    
    int pop() {
        if (topInd == -1) return -1;
        int res = stk[topInd] + incArr[topInd];
        if (topInd >= 1) {
            incArr[topInd-1] += incArr[topInd];
        }
        incArr[topInd] = 0;
        topInd--;
        return res;
    }
    
    void increment(int k, int val) {
        if (topInd == -1) return;
        incArr[min(topInd, k-1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */