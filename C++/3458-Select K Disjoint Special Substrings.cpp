// https://leetcode.com/problems/select-k-disjoint-special-substrings/solutions/6427669/easy-to-understand-c-code/
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int N = s.size();
        vector<int> first(26, -1), last(26, -1);
        vector<pair<int, int>> intervals;
        for (int i=0; i<N; i++) {
            if (first[s[i]-'a'] == -1) {
                first[s[i]-'a'] = i;
            }
            last[s[i]-'a'] = i;
        }

        for (int i=0; i<N; i++) {
            int charNum = s[i]-'a';
            if (i != first[charNum]) continue;

            int j = last[charNum];
            for (int k=i; k<=j; k++) {
                j = max(j, last[s[k]-'a']);
            }

            bool overlap = false;
            for (int k=i; k<=j; k++) {
                if (first[s[k]-'a'] < i) {
                    overlap = true;
                    break;
                }
            }
            if (overlap) continue;
            if (i == 0 && j == N-1) continue;
            intervals.push_back({i, j});
        }


        sort(begin(intervals), end(intervals), [](auto &a, auto &b){
            return a.second < b.second;
        });

        int prev = -1, cnt = 0;
        for (auto &[s, e]:intervals) {
            if (s > prev) {
                prev = e;
                cnt++;
            }
        }

        return cnt >= k;
    }
};