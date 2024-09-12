class Solution {
public:
    bool isVowel(char c) {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> hmap = {{0, -1}};
        int curr = 0, N = s.size(), res = 0;
        for (int i=0; i<N; i++) {
            if (isVowel(s[i])) {
                curr ^= (1<<(s[i]-'a'));
                if (!hmap.contains(curr)) {
                    hmap[curr] = i;
                }            
            }
            res = max(res, i-hmap[curr]);
        }
        return res;
    }
};