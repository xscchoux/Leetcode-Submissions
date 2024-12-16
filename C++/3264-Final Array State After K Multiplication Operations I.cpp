class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k-- > 0) {
            auto [val, idx] = pq.top();
            pq.pop();
            nums[idx] *= multiplier; 
            pq.push({val*multiplier, idx});
        }
        
        return nums;
    }
};