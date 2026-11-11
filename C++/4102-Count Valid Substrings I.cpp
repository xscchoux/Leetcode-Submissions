class Solution {
public:
    long long countValidSubstrings(string s) {
        vector<int> pos;
        int N = s.size();
        for (int i=0; i<N-2; i++) {
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                pos.push_back(i);
            }
        }

        if (pos.empty()) {
            return (long long)N*(N+1)/2;
        }

        int posIdx = 0;
        int prev = -1;
        long long res = 0;
        for (int i=0; i<N; i++) {
            res += i - prev;
            if (i-pos[posIdx] == 1) {
                prev = pos[posIdx];
                if (posIdx < pos.size()-1) {
                    posIdx++;
                }
            }
        }

        return res;
    }
};