class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int res = 0, left = 0;

        for (int i=0; i<fruits.size(); i++) {
            cnt[fruits[i]]++;
            while (cnt.size() > 2) {
                cnt[fruits[left]]--;
                if (cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            res = max(i-left+1, res);
        }
        return res;
    }
};