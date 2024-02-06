class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        vector<vector<string>> res;
        for (string s:strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            hmap[s].push_back(tmp);
        }
        
        for (const auto &kv:hmap) {
            res.push_back(kv.second);
        }
        
        return res;
    }
};