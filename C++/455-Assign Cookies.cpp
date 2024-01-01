class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx1 = 0, idx2 = 0;
        
        while (idx1 < g.size() && idx2 < s.size()){
            if (s[idx2] >= g[idx1]){
                idx1++;
            }
            idx2++;
        }
        return idx1;
    }
};