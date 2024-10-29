// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/solutions/5905505/top-and-bottom/
using LL = long long;
using PIL = pair<int, LL>;
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<PIL> top, bot;
        unordered_map<int, LL> counter;
        LL running = 0;
        int N = nums.size();
        vector<LL> res;
        for (int i=0; i<N; i++) {
            LL count = counter[nums[i]];
            if (count) {
                if (top.find({count, nums[i]}) != top.end()) {
                    running -= count*nums[i];
                    top.erase({count, nums[i]});
                } else {
                    bot.erase({count, nums[i]});
                }
            }
            counter[nums[i]]++;
            top.insert({count+1, nums[i]});
            running += (count+1)*nums[i];
            if (top.size() > x) {
                auto it_top = top.begin();
                running -= it_top->first*it_top->second;
                bot.insert({it_top->first, it_top->second});
                top.erase(it_top);
            }
            if (i>=k) {
                LL deleteCnt = counter[nums[i-k]];
                if (top.find({deleteCnt, nums[i-k]}) != top.end()) {
                    running -= deleteCnt*nums[i-k];
                    top.erase({deleteCnt, nums[i-k]});
                } else {
                    bot.erase({deleteCnt, nums[i-k]});
                }
                counter[nums[i-k]]--;
                if (deleteCnt > 1) {
                    bot.insert({deleteCnt-1, nums[i-k]});
                }
                if (top.size() < x && !bot.empty()) {
                    auto it_bot = prev(bot.end());
                    running += it_bot->first*it_bot->second;
                    top.insert({it_bot->first, it_bot->second});
                    bot.erase(it_bot);
                }
            }
            if (i >= k-1) {
                res.push_back(running);
            }
        }
        return res;
    }
};