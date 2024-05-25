class Solution {
private:
    int Ns, Np;
public:
    bool dfs(int ind_s, int ind_p, unordered_map<char, string> &hmap, unordered_set<string> &wordSet, string &s, string &pattern) {
        if (ind_s == Ns && ind_p == Np) {
            return true;
        } else if (ind_s == Ns || ind_p == Np) {
            return false;
        }

        for (int i=ind_s; i < Ns; i++) {
            string tmp_s = s.substr(ind_s, i-ind_s+1);
            if (hmap.find(pattern[ind_p]) == hmap.end()) {
                if (wordSet.find(tmp_s) != wordSet.end()) continue;
                hmap[pattern[ind_p]] = tmp_s;
                wordSet.insert(tmp_s);
                if (dfs(i+1, ind_p+1, hmap, wordSet, s, pattern)) {
                    return true;
                }
                hmap.erase(pattern[ind_p]);
                wordSet.erase(tmp_s);
            } else {
                if (hmap[pattern[ind_p]] != tmp_s) continue;
                if (dfs(i+1, ind_p+1, hmap, wordSet, s, pattern)){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> hmap;
        unordered_set<string> wordSet;
        Ns = s.size();
        Np = pattern.size();
        return dfs(0, 0, hmap, wordSet, s, pattern);
    }
};