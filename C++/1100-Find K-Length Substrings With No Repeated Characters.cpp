// first AC
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26) return 0;
        int res = 0;
        vector<int> cnt(26, 0);
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]-'a']++;
            if (i >= k) cnt[s[i-k]-'a']--;
            if (i >= k-1) {
                bool unique = true;
                for (int kk=0; kk<26; kk++) {
                    if (cnt[kk] >= 2) {
                        unique = false;
                        break;
                    }
                }
                if (unique) res++;
            }
        }

        return res;
    }
};


// Better
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26) return 0;
        int res = 0, left = 0;
        vector<int> cnt(26, 0);
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]-'a']++;
            while (cnt[s[i]-'a'] > 1) {
                cnt[s[left++]-'a']--;
            }
            
            if (i-left+1 == k) {
                res++;
                cnt[s[left++]-'a']--;
            }
        }

        return res;
    }
};