// O(26*n)
// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/743223/c-java-greedy-o-n/
using PII = pair<int, int>;
class Solution {
public:
    int getRight(string& s, unordered_map<char, PII>& hmap, int L, int R) {
        int rightMost = R;
        for (int i=L; i<=rightMost; i++) {
            if (hmap[s[i]].first < L) return -1;
            rightMost = max(rightMost, hmap[s[i]].second);
        }
        return rightMost;
    }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, PII> hmap;
        int N = s.size();
        for (int i=0; i<N; i++) {
            if (!hmap.contains(s[i])) {
                hmap[s[i]] = {i, i};
            } else {
                hmap[s[i]].second = i;
            }
        }

        vector<string> res;
        int right = -1;
        for (int i=0; i<N; i++) {
            auto &[currL, currR] = hmap[s[i]];
            if (i != currL) continue;
            int newRight = getRight(s, hmap, currL, currR);
            if (newRight == -1) continue;
            if (currL > right) {
                res.push_back(s.substr(i, newRight-i+1));
            } else {
                res.back() = s.substr(i, newRight-i+1);
            }
            right = newRight;
        }

        return res;
    }
};