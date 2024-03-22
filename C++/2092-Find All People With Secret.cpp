class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    void uni(int a, int b, vector<int>& parent) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        parent[pa] = pb;
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parent(n);
        for (int i=0; i<n; i++) parent[i] = i;
        parent[firstPerson] = 0;
        
        sort(meetings.begin(), meetings.end(), [&] (vector<int> a, vector<int> b) { return a[2] < b[2];});
        
        
        map<int, vector<vector<int>>> hmap;
        for (auto m:meetings) {
            hmap[m[2]].push_back({m[0], m[1]});
        }
        
        unordered_set<int> res;
        res.insert(0);
        res.insert(firstPerson);
        
        for (auto &kv:hmap) {
            
            for (auto &arr:kv.second) {
                uni(arr[0], arr[1], parent);
            }
            for (auto &arr:kv.second) {
                if (find(arr[0], parent) == find(0, parent)) {
                    res.insert(arr[0]);
                    res.insert(arr[1]);
                } else {
                    parent[arr[0]] = arr[0];
                    parent[arr[1]] = arr[1];                    
                }
            }
        
        }
        return vector<int>(res.begin(), res.end());
    }
};