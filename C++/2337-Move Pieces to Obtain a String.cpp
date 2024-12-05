class Solution {
public:
    bool canChange(string start, string target) {
        int idx1=0, idx2=0, N1=start.size(), N2=target.size();

        while (idx1<N1 || idx2<N2) {
            while (idx1 < N1 && start[idx1] != 'L' && start[idx1] != 'R') {
                idx1++;
            }
            while (idx2 < N2 && target[idx2] != 'L' && target[idx2] != 'R') {
                idx2++;
            }
            if (start[idx1] != target[idx2]) return false;
            if (start[idx1] == 'L' && idx1 < idx2) return false;
            if (target[idx2] == 'R' && idx1 > idx2) return false;
            idx1++;
            idx2++;
        }

        return true;
    }
};