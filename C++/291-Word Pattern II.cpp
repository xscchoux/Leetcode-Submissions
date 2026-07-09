class Solution {
private:
    int Ns, Np;
public:
    bool dfs(int idx_p, int idx_s, string& pattern, string& s, unordered_map<char, string>& hmap, unordered_set<string>& used) {
        if (idx_p == Np && idx_s == Ns) {
            return true;
        } else if (idx_p == Np || idx_s == Ns) {
            return false;
        }

        char curr = pattern[idx_p];

        if (hmap.contains(curr)) {
            int sz = hmap[curr].size();
            if (Ns-idx_s < sz || s.substr(idx_s, sz) != hmap[curr]) {
                return false;
            }
            return dfs(idx_p+1, idx_s + sz, pattern, s, hmap, used);
        }

        string nxtString = "";

        for (int j = idx_s; j < Ns; j++) {
            if (Ns-idx_s < Np - idx_p) break;
            nxtString.push_back(s[j]);
            if (used.contains(nxtString)) continue;
            
            hmap[curr] = nxtString;
            used.insert(nxtString);
            if (dfs(idx_p+1, idx_s + nxtString.size(), pattern, s, hmap, used)){
                return true;
            }
            used.erase(nxtString);
            hmap.erase(curr);
        }

        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        this->Np = pattern.size();
        this->Ns = s.size();
        
        unordered_map<char, string> hmap;
        unordered_set<string> used;
        
        auto res = dfs(0, 0, pattern, s, hmap, used);

        return res;
    }
};