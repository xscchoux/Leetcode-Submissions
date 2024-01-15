class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> hmap;
        for (int i=0; i<s.size(); i++){
            hmap[s[i]]++;
            hmap[t[i]]--;
        }
        int diff = 0;
        for (auto it = hmap.begin(); it != hmap.end(); it++) {
            diff += max(0, hmap[it->first]);
        }
        
        return diff;
    }
};