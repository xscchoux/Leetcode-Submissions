using LL = long long;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        LL res = 0;
        priority_queue<int, vector<int>> pq;
        for (int num:nums) pq.push(num);

        while (k--) {
            int val = pq.top();
            res += val;
            pq.pop();
            pq.push(ceil((double)val/3));
        }

        return res;
    }
};