class Solution {
public:
    int getSorted(int num) {
        string s = to_string(num);
        sort(begin(s), end(s), greater<>());
        return stoi(s);
    }
    long long maximizeSum(vector<int>& nums, int k) {
        long long tot = accumulate(begin(nums), end(nums), 0LL);
        priority_queue<int> pq;

        for (int num:nums) {
            pq.push(getSorted(num)-num);
        }

        long long res = 0;
        while (!pq.empty()) {
            int diff = pq.top();
            pq.pop();
            if (k > 0) {
                tot += diff;
                k--;
            } else {
                break;
            }
        }

        return tot;
    }
};