// We can prove by contradiction: what happens if words[i], words[j] not in (words[0], words[N-1]) 
class Solution {
public:
    int maxDistance(vector<string>& words) {
        int N = words.size();
        if (N == 1) return 0;

        if (words[0] != words[N-1]) return N;

        int res = 0;
        for (int i=1; i<N-1; i++) {
            if (words[N-1] != words[i]) {
                res = max(res, N-i);
                break;
            }
        }

        for (int i=N-2; i>=1; i--) {
            if (words[0] != words[i]) {
                res = max(res, i+1);
                break;
            }
        }

        return res;
    }
};