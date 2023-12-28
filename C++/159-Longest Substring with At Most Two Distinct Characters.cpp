class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> count;
        int res = 0;
        int left = 0;
        for (int i=0; i<s.size(); i++){
            count[s[i]]++;
            while (count.size() > 2){
                count[s[left]]--;
                if (count[s[left]] == 0) count.erase(s[left]);
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};