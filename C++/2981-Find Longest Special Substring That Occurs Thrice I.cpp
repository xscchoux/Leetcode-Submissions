// O(n^2)
class Solution {
public:
    int maximumLength(string s) {
        int N = s.size();
        // cannot use unordered_map<pair<char, int>, int> hmap here.
        // std::pair<char, int> does not work because the standard library's default hash implementations may not include a specialization for this combination.
        map<pair<char, int>, int> hmap;
        for (int i=N-1; i>=0; i--) {
            char curr = s[i];
            int cnt = 0;
            for (int j=i; j>=0; j--) {
                if (s[i] == s[j]) cnt++, hmap[{curr, cnt}]++;
                else break;
            }
        }

        int res = -1;
        for (auto &[k, v]:hmap) {
            if (v >= 3) {
                res = max(res, k.second);
            }
        }

        return res;
    }
};




// clever O(n) solution
class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> maxCnt(26, {0, 0, 0}); // keep lengths of the 3 longest special strings for a...z 
        int i=0, j=0, N=s.size();
        while (j < N) {
            if (i!=j && s[i] != s[j]) {
                i=j;
            }
            int length = j-i+1;
            int charIdx = s[j]-'a';
            if (length > maxCnt[charIdx][0]) {
                maxCnt[charIdx][2] = maxCnt[charIdx][1];
                maxCnt[charIdx][1] = maxCnt[charIdx][0];
                maxCnt[charIdx][0] = length;
            } else if (length > maxCnt[charIdx][1]) {
                maxCnt[charIdx][1] = maxCnt[charIdx][0];
                maxCnt[charIdx][0] = length;
            } else if (length > maxCnt[charIdx][2]) {
                maxCnt[charIdx][2] = length;
            }
            j++;
        }

        int res = -1;
        for (int i=0; i<26; i++) {
            if (maxCnt[i][2] != 0) {
                res = max(res, maxCnt[i][2]);
            }
        }
        return res;
    }
};