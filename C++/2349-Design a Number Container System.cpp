class NumberContainers {
public:
    // map1: index: value
    // map2: value: set of indices
    unordered_map<int, int> m;
    unordered_map<int, set<int>> number2indices;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (m.contains(index)) {
            int prevNum = m[index];
            number2indices[prevNum].erase(index);
            if (number2indices[prevNum].empty()) {
                number2indices.erase(prevNum);
            }
        }
        m[index] = number;
        number2indices[number].insert(index);
    }
    
    int find(int number) {
        if (!number2indices.contains(number)) {
            return -1;
        }
        return *number2indices[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */


// priority queue
class NumberContainers {
public:
    // map1: index: value
    // map2: value: priority queue of indices
    unordered_map<int, int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> number2indices;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        number2indices[number].push(index);
        m[index] = number;
    }
    
    int find(int number) {
        if (number2indices[number].empty()) return -1;
        while (!number2indices[number].empty()) {
            int idx = number2indices[number].top();
            if (m[idx] == number) {
                return idx; 
            }
            number2indices[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */