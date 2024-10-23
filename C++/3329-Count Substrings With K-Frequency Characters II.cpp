class Solution {
public:
    bool check(int cnt[], int k) {
        for (int i=0; i<26; i++) {
            if (cnt[i]>=k) return true;
        }
        return false;
    }
    long long numberOfSubstrings(string s, int k) {
        int cnt[26];
        int left = 0, N = s.size();
        long long res=0;
        for (int i=0; i<N; i++) {
            cnt[s[i]-'a']++;
            if (check(cnt, k)) {
                while (check(cnt, k)) {
                    cnt[s[left]-'a']--;
                    left++;
                }
                res += left;
                left--;
                cnt[s[left]-'a']++;
            }
        }
        return res;
    }
};



// More clever solution
class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        long long res = 0;
        int cnt[26], left = 0, N = s.size();
        for (int i=0; i<N; i++) {
            cnt[s[i]-'a']++;
            while (cnt[s[i]-'a'] == k) {
                res += N-i;
                cnt[s[left++]-'a']--;
            }
        }
        return res;
    }
};