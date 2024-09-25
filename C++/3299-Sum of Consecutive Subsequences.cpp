using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int getSum(vector<int>& nums) {
        unordered_map<int, pair<LL, LL>> hmap; // num: {sum of subsequences that ends with num, count of subsequences}
        LL res = 0;
        for (int num:nums) {
            if (!hmap.contains(num)) {
                hmap[num] = {num, 1};
            } else {
                hmap[num].first = (hmap[num].first + num)%kMod;
                hmap[num].second += 1;
            }
            res = (res + num)%kMod;
            if (hmap.contains(num-1)) {
                auto [prevSum, cnt] = hmap[num-1];
                LL toAdd = (prevSum + num*cnt)%kMod;
                res = (res + toAdd)%kMod;
                hmap[num].first = (hmap[num].first + toAdd)%kMod;
                hmap[num].second += cnt;
            }
        }

        reverse(begin(nums), end(nums));

        unordered_map<int, pair<LL, LL>> hmap2;
        for (int num:nums) {
            if (!hmap2.contains(num)) {
                hmap2[num] = {num, 1};
            } else {
                hmap2[num].first = (hmap2[num].first + num)%kMod;
                hmap2[num].second += 1;
            }
            // res = (res + num)%kMod;
            if (hmap2.contains(num-1)) {
                auto [prevSum, cnt] = hmap2[num-1];
                LL toAdd = (prevSum + num*cnt)%kMod;
                res = (res + toAdd)%kMod;
                hmap2[num].first = (hmap2[num].first + toAdd)%kMod;
                hmap2[num].second += cnt;
            }
        }

        return res;
    }
};