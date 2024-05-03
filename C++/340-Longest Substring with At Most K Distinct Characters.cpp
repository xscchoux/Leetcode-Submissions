class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt = 0;
        int left = 0, res = 0;
        unordered_map<char, int> hmap;
        
        for (int i=0; i<s.size(); i++) {
            if (hmap[s[i]] == 0) cnt++;
            hmap[s[i]]++;
            if (cnt > k) {
                hmap[s[left]]--;
                if (hmap[s[left]] == 0){
                    cnt--;
                    // hmap.erase(s[left]);
                }
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};