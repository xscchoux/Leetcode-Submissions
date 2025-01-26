class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int N = nums.size();
        int groupNum = 0;
        vector<int> sortedNums = nums;
        sort(begin(sortedNums), end(sortedNums));
        unordered_map<int, int> groupMap; // index to group num
        unordered_map<int, deque<int>> grpNumToVal;  // group num to a deque of indexes

        groupMap[sortedNums[0]] = groupNum;
        grpNumToVal[groupNum].push_back(sortedNums[0]);

        for (int i=1; i<N; i++) {
            if (sortedNums[i] - sortedNums[i-1] > limit) {
                groupMap[sortedNums[i]] = ++groupNum;
            } else {
                groupMap[sortedNums[i]] = groupNum;
            }
            grpNumToVal[groupNum].push_back(sortedNums[i]);
        }

        vector<int> res;
        for (int i=0; i<N; i++) {
            int grpNum = groupMap[nums[i]];
            res.push_back(grpNumToVal[grpNum].front());
            grpNumToVal[grpNum].pop_front();
        }

        return res;
    }
};