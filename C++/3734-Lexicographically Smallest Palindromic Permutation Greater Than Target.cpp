 class Solution {
public:
    string res = "";
    char midChar = '\0';
    bool backtracking(int idx, map<char, int>& cnt, int length, string& target, string& s, bool prevGreater) {
        if (idx == length) {
            string reversed = string(s.rbegin(), s.rend()), curr;
            if (midChar == '\0') {
                curr = s + reversed;
            } else {
                curr = s + midChar + reversed;
            }
            
            if (curr > target) {
                res = curr;
                return true;
            }
            return false;
        }

        char targetChar = target[idx];
        if (prevGreater) {
            char firstChar = begin(cnt)->first;
            s += firstChar;
            cnt[firstChar]--;
            if (cnt[firstChar] == 0) cnt.erase(firstChar);
            if (backtracking(idx+1, cnt, length, target, s, prevGreater)) {
                return true;
            }
            cnt[firstChar]++;
            s.pop_back();
        } else {
            // pick the char equal or greater than targetChar
            auto it = cnt.lower_bound(targetChar);
            if (it != cnt.end()) {
                char firstChar = it->first;
                s += firstChar;
                cnt[firstChar]--;
                if (cnt[firstChar] == 0) cnt.erase(firstChar);
                if (backtracking(idx+1, cnt, length, target, s, firstChar > targetChar)) {
                    return true;
                }
                cnt[firstChar]++;  
                s.pop_back();

                if (firstChar == targetChar) {
                    auto it2 = cnt.upper_bound(targetChar);
                    if (it2 != cnt.end()) {
                        char firstChar2 = it2->first;
                        s += firstChar2;
                        cnt[firstChar2]--;
                        if (cnt[firstChar2] == 0) cnt.erase(firstChar2);
                        if (backtracking(idx+1, cnt, length, target, s, true)) {
                            return true;
                        }
                        cnt[firstChar2]++;
                        s.pop_back();
                    }             
                }
            }
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        if (s.size() == 1) {
            if (s[0] > target[0]) return s;
            else return "";
        }

        map<char, int> cnt;
        for (char c:s) {
            cnt[c]++;
        }
        
        bool cntOne = false;
        for (auto &[k, v]:cnt) {
            if (v & 1) {
                if (cntOne) {
                    return "";
                }
                cntOne = true;
                midChar = k;
            }
        }

        int N = target.size();

        if (N&1) {
            cnt[midChar]--;
            if (cnt[midChar] == 0) {
                cnt.erase(midChar);
            }
        }

        for (auto &[k, v]:cnt) {
            cnt[k] /=2;
        }

        string tmp = "";
        backtracking(0, cnt, N/2, target, tmp, false);

        return res;
    }
};