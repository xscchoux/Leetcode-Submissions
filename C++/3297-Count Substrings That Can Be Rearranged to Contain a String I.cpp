using LL = long long;
class Solution {
public:
    bool enough(vector<int>& cnt1, vector<int>& cnt2) {
        for (int i=0; i<26; i++) {
            if (cnt1[i] < cnt2[i]) return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        vector<int> cnt2(26, 0), cnt1(26, 0);

        for (char w:word2) cnt2[w-'a']++;

        int left = 0;
        LL res = 0;

        for (int i=0; i<word1.size(); i++) {
            cnt1[word1[i]-'a']++;
            while (enough(cnt1, cnt2)) {
                cnt1[word1[left]-'a']--;
                left++;
            }
            res += left;
        }

        return res;
    }
};