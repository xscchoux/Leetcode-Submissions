// class Solution {
// public:
//     static constexpr int maxCourse = 100;
//     // void merge(bitset<maxCourse>& prev, bitset<maxCourse>& curr) {
//     //     curr |= prev;
//     // }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         int N = numCourses;
//         vector<bitset<maxCourse>> parent(N);
//         vector<int> indegree(N);
//         vector<vector<int>> graph(N);

//         for (auto& p:prerequisites) {
//             int u = p[0], v = p[1];
//             graph[u].push_back(v);
//             parent[v].set(u);
//             // parent[v].insert(u);
//             indegree[v]++;
//         }

//         queue<int> q;
//         for (int i=0; i<N; i++) {
//             if (indegree[i] == 0) q.push(i);
//         }

//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             for (int nxt:graph[curr]) {
//                 indegree[nxt]--;
//                 parent[nxt] |= parent[curr];
//                 // merge(parent[curr], parent[nxt]);
//                 if (indegree[nxt] == 0) {
//                     q.push(nxt);
//                 }
//             }
//         }
        
//         vector<bool> res;
//         for (auto q:queries) {
//             int u = q[0], v = q[1];
//             res.push_back(parent[v].test(u));
//             // if (parent[v].contains(u)) {
//             //     res.push_back(true);
//             // } else {
//             //     res.push_back(false);
//             // }
//         }

//         return res;
//     }
// };


class Solution {
public:
    void merge(vector<unordered_set<int>>& parent, int prev, int curr) {
        for (int num:parent[prev]) {
            parent[curr].insert(num);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int N = numCourses;
        vector<unordered_set<int>> parent(N);
        vector<int> indegree(N);
        vector<vector<int>> graph(N);

        for (auto& p:prerequisites) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            parent[v].insert(u);
            indegree[v]++;
        }

        queue<int> q;
        for (int i=0; i<N; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nxt:graph[curr]) {
                indegree[nxt]--;
                merge(parent, curr, nxt);
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        
        vector<bool> res;
        for (auto& q:queries) {
            int u = q[0], v = q[1];
            if (parent[v].contains(u)) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};


// use bitset instead of unordered_set, faster
class Solution {
public:
    static constexpr int maxCourse = 100;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int N = numCourses;
        vector<bitset<maxCourse>> parent(N);
        vector<int> indegree(N);
        vector<vector<int>> graph(N);

        for (auto& p:prerequisites) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            parent[v].set(u);
            indegree[v]++;
        }

        queue<int> q;
        for (int i=0; i<N; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nxt:graph[curr]) {
                indegree[nxt]--;
                parent[nxt] |= parent[curr];
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        
        vector<bool> res;
        for (auto& q:queries) {
            int u = q[0], v = q[1];
            res.push_back(parent[v].test(u));
        }

        return res;
    }
};


