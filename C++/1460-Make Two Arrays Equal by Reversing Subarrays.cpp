class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hmap1, hmap2;
        for (int num:target) {
            hmap1[num]++;
        }
        for (int num:arr) {
            hmap2[num]++;
        }
        return hmap1 == hmap2;
    }
};