// two maps
class matrix3D {
public:
    vector<vector<vector<int>>> matrix;
    map<int, set<int>, greater<>> count2Row; // count:rows
    unordered_map<int, int> cnt; // row:count
    matrix3D(int n) {
        matrix.resize(n, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i=0; i<n; i++) count2Row[0].insert(i);
    }
    
    void setCell(int x, int y, int z) {
        if (matrix[x][y][z] == 0) {
            matrix[x][y][z] = 1;
            count2Row[cnt[x]].erase(x);
            if (count2Row[cnt[x]].empty()) count2Row.erase(cnt[x]);
            count2Row[cnt[x]+1].insert(x);
            cnt[x] += 1;
        }
    }
    
    void unsetCell(int x, int y, int z) {
        if (matrix[x][y][z] == 1) {
            matrix[x][y][z] = 0;
            count2Row[cnt[x]].erase(x);
            if (count2Row[cnt[x]].empty()) count2Row.erase(cnt[x]);
            count2Row[cnt[x]-1].insert(x);
            cnt[x] -= 1;
        }        
    }
    
    int largestMatrix() {
        return *count2Row.begin()->second.rbegin();
    }
};

/**
 * Your matrix3D object will be instantiated and called as such:
 * matrix3D* obj = new matrix3D(n);
 * obj->setCell(x,y,z);
 * obj->unsetCell(x,y,z);
 * int param_3 = obj->largestMatrix();
 */



// Use priority queue, even faster
class matrix3D {
public:
    vector<vector<vector<int>>> matrix;
    priority_queue<pair<int, int>> pq;  // add any new results : {count, row}
    unordered_map<int, int> cnt; // row:count
    matrix3D(int n) {
        matrix.resize(n, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i=0; i<n; i++) pq.push({0, i});
    }
    
    void setCell(int x, int y, int z) {
        if (matrix[x][y][z] == 0) {
            matrix[x][y][z] = 1;
            cnt[x] += 1;
            pq.push({cnt[x], x});
        }
    }
    
    void unsetCell(int x, int y, int z) {
        if (matrix[x][y][z] == 1) {
            matrix[x][y][z] = 0;
            cnt[x] -= 1;
            pq.push({cnt[x], x});
        }        
    }
    
    int largestMatrix() {
        while (pq.top().first != cnt[pq.top().second]) {
            pq.pop();
        }
        return pq.top().second;
    }
};