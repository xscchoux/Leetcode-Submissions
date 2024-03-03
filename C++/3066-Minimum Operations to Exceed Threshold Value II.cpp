class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        int ops = 0;
        for (int num:nums) {
            pq.push(num);
        }
        while (!pq.empty() && pq.size() >= 2 && pq.top() < k) {
            long n1 = pq.top(); pq.pop();
            long n2 = pq.top(); pq.pop();
            ops++;
            pq.push(n1*2+n2);
        }
        
        return ops;
    }
};