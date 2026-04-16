class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> pos;     // num:positions
        int N = nums.size();

        for (int i=0; i<nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> res;

        for (int q:queries) {
            int num = nums[q];
            if (pos[num].size() == 1) {
                res.push_back(-1);
                continue;
            }
            
            int val = INT_MAX;
            auto upperIt = upper_bound(begin(pos[num]), end(pos[num]), q);
            if (upperIt != end(pos[num])) {
                val = min(val, *upperIt - q );
            } else {
                val = min(val,  N - q + *begin(pos[num]) );
            }

            auto lowerIt = lower_bound(begin(pos[num]), end(pos[num]), q);
            if (lowerIt != begin(pos[num])) {
                val = min(val,  q - *(lowerIt-1) );
            } else {
                val = min(val, q + N - *rbegin(pos[num]) );
            }
            
            res.push_back(val);
        }

        return res;
    }
};




class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int N = nums.size();
        
        // leftClosest[i]: the nearest index to the left of i with the same value
        // rightClosest[i]: the nearest index to the right of i with the same value
        
        vector<int> leftClosest(N, -1), rightClosest(N, -1);
        unordered_map<int, int> pos;  // position of nums[i];

        // a doubled nums of length 2*N starting from index -N to N-1
        for (int i=-N; i<N; i++) {
            if (i >= 0) {
                leftClosest[i] = pos[nums[i]];
            }
            pos[nums[(i+N)%N]] = i;
        }

        // a doubled nums of length 2*N starting from index 0 to 2*N-1        
        for (int i=2*N-1; i>=0; i--) {
            if (i < N) {
                rightClosest[i] = pos[nums[i]];
            }
            pos[nums[i%N]] = i;
        }

        vector<int> res;
        for (int q:queries) {
            if (q - leftClosest[q] == N) res.push_back(-1);
            else {
                res.push_back(min(q-leftClosest[q], rightClosest[q]- q));
            }
        }

        return res;
    }
};
