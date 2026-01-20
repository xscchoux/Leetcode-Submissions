// For selecting two machines, fix machine i and binary search the largest index j < i with costs[j] < budget - costs[i].
// Update the answer with capacity[i] + prefMax[j] whenever such j exists.

// First AC
class Solution {
public:
    int bs(int idx, vector<int>& costs, vector<int>& maxCapacitySoFar, int budget) {
        int left = 0, right = idx-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (costs[mid] > budget) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (costs[right] <= budget) {
            return maxCapacitySoFar[right];
        } else if (costs[left] <= budget) {
            return maxCapacitySoFar[left];
        } else {
            return 0;
        }
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int N = costs.size();
        vector<int> index(N, 0);
        iota(begin(index), end(index), 0);

        sort(begin(index), end(index), [&](int a, int b) {
            return costs[a] < costs[b] || (costs[a] == costs[b] && capacity[a] > capacity[b]); 
        });
        
        sort(begin(costs), end(costs));
        vector<int> sortedCapacity;
        for (int i=0; i<N; i++) {
            sortedCapacity.push_back(capacity[index[i]]);
        }
        
        vector<int> maxCapacitySoFar(N, 0);
        maxCapacitySoFar[0] = sortedCapacity[0];
        for (int i=1; i<N; i++) {
            maxCapacitySoFar[i] = max(sortedCapacity[i], maxCapacitySoFar[i-1]);
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            if (costs[i] >= budget) break;
            else if (costs[i] == budget - 1) {
                res = max(res, sortedCapacity[i]);
                break;
            }
            int curr = 0;
            curr += sortedCapacity[i];
            if (i==0) {
                res = max(res, curr);
            } else {
                int remainCapacity = bs(i, costs, maxCapacitySoFar, budget-costs[i]-1);
                res = max(res, curr + remainCapacity);
            }
        }
        
        return res;
    }
};



// A bit faster
class Solution {
public:
    int bs(int idx, vector<pair<int, int>>& sortedPair, vector<int>& maxCapacitySoFar, int budget) {
        int left = 0, right = idx-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (sortedPair[mid].first > budget) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (sortedPair[right].first <= budget) {
            return maxCapacitySoFar[right];
        } else if (sortedPair[left].first <= budget) {
            return maxCapacitySoFar[left];
        } else {
            return 0;
        }
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int N = costs.size();

        vector<pair<int, int>> sortedPair;
        for (int i=0; i<N; i++) {
            if (costs[i] >= budget) continue;
            sortedPair.push_back({costs[i], capacity[i]});
        }

        if (sortedPair.empty()) return 0;

        sort(begin(sortedPair), end(sortedPair));

        vector<int> maxCapacitySoFar(N, 0);
        maxCapacitySoFar[0] = sortedPair[0].second;
        for (int i=1; i<sortedPair.size(); i++) {
            maxCapacitySoFar[i] = max(sortedPair[i].second, maxCapacitySoFar[i-1]);
        }

        int res = 0;
        for (int i=0; i<sortedPair.size(); i++) {
            int curr = sortedPair[i].second;
            if (i==0) {
                res = max(res, curr);
            } else {
                int remainCapacity = bs(i, sortedPair, maxCapacitySoFar, budget-sortedPair[i].first-1);
                res = max(res, curr + remainCapacity);
            }
        }
        
        return res;
    }
};