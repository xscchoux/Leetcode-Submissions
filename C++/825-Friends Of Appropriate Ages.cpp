class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // y...x
        // 1. x >= y
        // 2. y > 0.5*x+7
        sort(ages.begin(),ages.end());
        int res = 0;
        for (int i=0; i<ages.size(); i++) {            
            if (ages[i] <= 0.5*ages[i] + 7) continue;
            int idx1 = upper_bound(ages.begin(), ages.end(), 0.5*ages[i] + 7) - ages.begin();
            int idx2 = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            idx2--;
            if (idx2 > idx1) res += idx2-idx1;
        }
        return res;
    }
};
