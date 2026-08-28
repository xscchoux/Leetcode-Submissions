// backtracking
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


// Straightforward sequential enumeration (slower but easy to understand)
class Solution {
public:
    int check(vector<int>& cnt, string& prefix, char added, string& mid, string& target) {
        string left = prefix;
        left.push_back(added);

        for (int i=25; i>=0; i--) {
            if (cnt[i] == 0) continue;
            left.append(cnt[i], 'a' + i);
        }

        string reversed_left = left;
        reverse(begin(reversed_left), end(reversed_left));
        string palindrome = left + mid + reversed_left;

        return palindrome > target;
    }
    string lexPalindromicPermutation(string s, string target) {
        int N = s.size();
        if (N == 1) {
            return s > target? s: "";
        }

        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c-'a']++;
        }

        bool hasOdd = false;
        string mid = "";
        for (int i=0; i<26; i++) {
            if (cnt[i]&1) {
                if (hasOdd) {
                    return "";
                }
                mid = string(1, 'a' + i);
                hasOdd = true;
            }
            cnt[i] /= 2;
        }

         // Construct the left part of each digit greedily
        string prefix = "";
        for (int i=0; i<N/2; i++) {
            bool found = false;
            for (int j=0; j<26; j++) {
                if (cnt[j] == 0) continue;
                cnt[j]--;
                if (check(cnt, prefix, 'a' + j, mid, target)) {
                    prefix.push_back('a'+j);
                    found = true;
                    break;
                } else {
                    cnt[j]++;
                }
            }

            if (!found) return "";
            if (prefix[i] > target[i]) {
                for (int k=0; k<26; k++) {
                    if (cnt[k] == 0) continue;
                    prefix.append(cnt[k], 'a'+k);
                }
                string reversed_prefix = prefix;
                reverse(begin(reversed_prefix), end(reversed_prefix));
                return prefix + mid + reversed_prefix;
            }
        }

         // Construct the final string
        string reversed_prefix = prefix;
        reverse(begin(reversed_prefix), end(reversed_prefix));
        return prefix + mid + reversed_prefix;

    }
};