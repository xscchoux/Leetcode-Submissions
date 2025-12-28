// This is a finite state machine where:

// Each remainder is a node
// Each node has exactly one outgoing edge
// So we have at most k states

class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k%2 == 0) return -1;
        
        int rem = 1%k, cnt = 1;
        unordered_set<int> visited;
        while (true) {
            if (rem == 0) {
                return cnt;
            } else if (visited.contains(rem)) {
                return -1;
            } else {
                visited.insert(rem);
                rem = (rem*10+1)%k;
                cnt++;
            }
        }

        return 0;
    }
};