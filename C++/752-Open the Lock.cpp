class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end()) return -1;
        
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int step = 0;
        
        while (!q.empty()) {
            int length = q.size();
            while (length > 0) {
                string curr = q.front();
                q.pop();
                if (curr == target) return step;
                for (int i=0; i<4; i++) {
                    char tmp = curr[i];
                    curr[i] = (curr[i] - '0' + 1)%10 + '0';
                    if (visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = tmp;
                }
                for (int i=0; i<4; i++) {
                    char tmp = curr[i];
                    curr[i] = (curr[i] - '0' - 1 + 10)%10 + '0';
                    if (visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = tmp;
                }
                length--;
            }
            step++;
        }
        return -1;
    }
};