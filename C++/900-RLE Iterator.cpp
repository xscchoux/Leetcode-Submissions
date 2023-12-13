class RLEIterator {
public:
    deque<pair<int, int>> dq;
    RLEIterator(vector<int>& encoding) {        
        for (int i=0; i<encoding.size(); i+=2){
            if (encoding[i] == 0) continue;
            dq.push_back({encoding[i], encoding[i+1]});
        }
    }
    
    int next(int n) {
        int last = -1;
        while (n > 0 && !dq.empty()){
            auto [count, num] = dq.front();
            if (n >= count){
                dq.pop_front();
                n -= count;
            } else {
                dq.pop_front();
                dq.push_front({count-n, num});
                n = 0;
            }
            last = num;
        }
        if (n > 0 && dq.empty()) return -1;
        
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */


// Solution 2 using iterator, more convenient

class RLEIterator {
public:
    vector<int> arr;
    vector<int>::iterator it;
    RLEIterator(vector<int>& encoding) {
        arr = encoding;
        it = arr.begin();
    }
    
    int next(int n) {
        if (it == arr.end()) return -1;
        
        if (n <= *it){
            *it -= n;
            return *(it+1);
        } else {
            int tmp = *it;
            it = it+2;
            return next(n-tmp);
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */