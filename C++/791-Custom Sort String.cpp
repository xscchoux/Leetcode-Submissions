class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> hmap;
        
        for (int i=0; i<order.size(); i++) {
            hmap[order[i]] = i;
        }
        
        sort(s.begin(), s.end(), [&](char a, char b){ return hmap[a] < hmap[b];});
        
        return s;
    }
};