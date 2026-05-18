// BFS
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int N = arr.size();
        vector<bool> visited(N, false);
        unordered_map<int, vector<int>> pos;
        
        for (int i=0; i<N; i++) {
            pos[arr[i]].push_back(i);
        }

        // this doesn't work

        // for (auto &[k, v]:pos) {
        //     if (v.size() == 1) {
        //         pos.erase(k); // this changes the container
        //     }
        // }

        for (auto it = pos.begin(); it != pos.end(); ) {
            if (it->second.size() == 1) {
                it = pos.erase(it);  // note that this returns the next iterator
            } else {
                ++it;
            }
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz-- > 0) {
                int curr = q.front();
                if (curr == N-1) return step;
                q.pop();

                if (pos.contains(arr[curr])) {
                    for (auto num:pos[arr[curr]]) {
                        if (visited[num]) continue;
                        visited[num] = true;
                        q.push(num);
                    }
                    pos[arr[curr]].clear();
                }


                if (curr + 1 < N && !visited[curr+1]) {
                    visited[curr+1] = true;
                    q.push(curr+1);
                }
                if (curr - 1 >= 0 && !visited[curr-1]) {
                    visited[curr-1] = true;
                    q.push(curr-1);
                }
            }
            step++;
        }

        return 0;
    }
};


// bidirectional BFS, hard and not faster
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int N = arr.size();
        if (N<=1) return 0;
        unordered_map<int, vector<int>> pos;

        for (int i=0; i<N; i++) {
            pos[arr[i]].push_back(i);
        }

        int step = 0;
        vector<bool> visited(N, false);
        visited[0] = true;
        visited[N-1] = true;
        set<int> frontSet = {0}, backSet = {N-1};

        while (!frontSet.empty()) {
            if (frontSet.size() > backSet.size()) {
                swap(frontSet, backSet);
            }

            set<int> nxt;
            for (int curr:frontSet) {
                for (int nxtIdx:pos[arr[curr]]) {
                    if (backSet.contains(nxtIdx)) return step+1;
                    if (!visited[nxtIdx]) {
                        visited[nxtIdx] = true;
                        nxt.insert(nxtIdx);
                    }
                }
                pos.erase(arr[curr]);

                if (curr + 1 < N) {
                    if (backSet.contains(curr+1)) return step+1;
                    if (!visited[curr+1]) {
                        visited[curr+1] = true;
                        nxt.insert(curr+1);
                    }
                }
                if (curr - 1 >= 0) {
                    if (backSet.contains(curr-1)) return step+1;
                    if (!visited[curr-1]) {
                        visited[curr-1] = true;
                        nxt.insert(curr-1);
                    }
                }
            }

            frontSet = nxt;
            step++;
        }

        return -1;
    }
};