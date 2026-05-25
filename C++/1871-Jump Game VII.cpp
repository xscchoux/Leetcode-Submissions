class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() != '0') return false;
        
        deque<int> dq;
        int N = s.size();
        dq.push_back(0);

        for (int i=1; i<N; i++) {
            if (s[i] == '0') {
                bool found = false;
                while (!dq.empty()) {
                    int prev = dq.front();
                    int dist = i-prev;
                    if (dist < minJump) {
                        break;
                    } else if (dist > maxJump) {
                        dq.pop_front();
                    } else {
                        if (i == N-1) return true;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    dq.push_back(i);
                }
            }
        }

        return false;
    }
};