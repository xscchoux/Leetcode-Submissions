class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char, int> hmap;
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            hmap[s[i]]++;
            auto [verticalMin, verticalMax] = minmax(hmap['N'], hmap['S']);
            auto [horizontalMin, horizontalMax] = minmax(hmap['W'], hmap['E']);
            
            res = max(res, verticalMax + horizontalMax + 2*(verticalMin+horizontalMin-max(0, verticalMin+horizontalMin-k)) - (verticalMin + horizontalMin));

        }
        return res;
    }
};