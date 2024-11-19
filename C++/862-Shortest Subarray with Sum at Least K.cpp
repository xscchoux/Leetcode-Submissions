// priority queue
using LL = long long;
using PLI = pair<LL, int>;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<PLI, vector<PLI>, greater<>> pq;
        int N = nums.size();
        vector<LL> preSum(N+1);
        preSum[0] = 0;

        LL running = 0;
        for (int i=0; i<N; i++) {
            running += nums[i];
            preSum[i+1] = running;
        }
        pq.push({0, -1});

        int res = INT_MAX;
        for (int i=0; i<N; i++) {
            while (!pq.empty() && preSum[i+1] - pq.top().first >= k) {
                res = min(res, i-pq.top().second);
                pq.pop();
            }
            pq.push({preSum[i+1], i});
        }

        return (res<INT_MAX)?res:-1;
    }
};


// deque
using LL = long long;
using PLI = pair<LL, int>;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<PLI> dq;
        int N = nums.size();
        LL running = 0;

        dq.push_front({0, -1});

        int res = INT_MAX;
        for (int i=0; i<N; i++) {
            running += nums[i];
            while (!dq.empty() && running - dq.front().first >= k) {
                res = min(res, i-dq.front().second);
                dq.pop_front();
            }
            while (!dq.empty() && running <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({running, i});
        }

        return (res<INT_MAX)?res:-1;
    }
};

// #include <iostream>
// using namespace std;
// deque without using pair<long long, int>, faster
using LL = long long;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        int N = nums.size();
        LL running = 0;
        vector<LL> preSum(N+1);

        for (int i=0; i<N; i++) {
            preSum[i+1] = nums[i] + preSum[i];
        }

        dq.push_front(0);

        int res = INT_MAX;
        for (int i=0; i<N; i++) {
            while (!dq.empty() && preSum[i+1] - preSum[dq.front()] >= k) {
                res = min(res, i+1-dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && preSum[i+1] <= preSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i+1);
        }

        return (res<INT_MAX)?res:-1;
    }
};