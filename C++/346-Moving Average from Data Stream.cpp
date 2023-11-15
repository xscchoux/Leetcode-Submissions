class MovingAverage {
public:
    int qSize;
    queue<int> q;
    double tot;
    
    MovingAverage(int size) {
        qSize = size;
        tot = 0;
    }
    
    double next(int val) {
        q.push(val);
        tot += val;
        if (q.size() > qSize){
            double last = q.front();
            tot -= last;
            q.pop();
        }
        return tot/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */