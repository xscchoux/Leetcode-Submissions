class Excel {
public:
    vector<vector<int>> matrix;
    map<pair<int, int>, multiset<pair<int, int>>> indegree;  // change parent -> change children
    // use multiset here because we may have this in numbers: [2,"B",["A1","A1"]]. Same parent (A1) may update its children (B2) multiple times
    Excel(int height, char width) {
        matrix.resize(height, vector<int>(width-'A'+1));
    }
    
    void topological_sort(int r, int c, int diff) {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            matrix[currR][currC] += diff;
            for (auto &[nxtR, nxtC]:indegree[{currR, currC}]) {
                q.push({nxtR, nxtC});
            }
        }
        // No circular reference here, Ex: mat[1]['A'] == sum(1, "B") and mat[1]['B'] == sum(1, "A").
        // So the topological sort will always end.
    }

    void set(int row, char column, int val) {
        int r = row-1, c = column-'A';
        for (auto it=indegree.begin(); it != indegree.end(); it++) {
            if (it->second.contains({r, c})) {
                it->second.erase({r, c});
            }
        }
        topological_sort(r, c, val-matrix[r][c]);
    }
    
    int get(int row, char column) {
        return matrix[row-1][column-'A'];
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int tot = 0;
        for (auto it=indegree.begin(); it != indegree.end(); it++) {
            int c = column -'A';
            int r = row-1;
            if (it->second.contains({r, c})) {
                it->second.erase({r, c});
            }
        }
        for (string num:numbers) {
            if (num.size() < 5) {
                int c = num[0]-'A';
                int r = stoi(num.substr(1))-1;
                indegree[{r, c}].insert({row-1, column-'A'});
                tot += matrix[r][c];
            } else {
                size_t index = num.find(":");
                int c1 = num[0]-'A', r1 = stoi(num.substr(1,index-1)) - 1;
                int c2 = num[index+1]-'A', r2 = stoi(num.substr(index+2)) - 1;
                for (int r=r1; r<=r2; r++) {
                    for (int c=c1; c<=c2; c++) {
                        indegree[{r, c}].insert({row-1, column-'A'});
                        tot += matrix[r][c];
                    }
                }                
            }
        }
        topological_sort(row-1, column-'A', tot-matrix[row-1][column-'A']);
        return matrix[row-1][column-'A'];
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */