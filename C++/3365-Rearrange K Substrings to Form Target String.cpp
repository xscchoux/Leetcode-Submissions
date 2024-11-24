class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> hmap;
        int N = s.size(), length = N/k;
        
        for (int i=0; i<N; i+=length) {
            hmap[s.substr(i, length)] += 1;    
        }
        for (int i=0; i<N; i+=length) {
            string part = t.substr(i, length);
            if (hmap.contains(part)) {
                hmap[part]--;
            } else {
                return false;
            }
            if (hmap[part] == 0) hmap.erase(part);
        }        

        return true;
    }
};