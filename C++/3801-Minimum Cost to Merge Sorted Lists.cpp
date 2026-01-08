// First AC, slow
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int N = lists.size();
        int states = pow(2, N);
        vector<long long> dp(states+1, LLONG_MAX), median(states+1, 0), length(states+1, 0);  // dp:minimum cost to merge into state

        for (int i=0; i<N; i++) {
            int state = pow(2, i);
            dp[state] = 0;
            length[state] = lists[i].size();
            median[state] = lists[i][(lists[i].size()-1)/2];
        }

        for (int state = 2; state < states; state++) {
            for (int subState = 1; subState < state; subState++) {
                if ((state & subState) != subState) continue;
                long long cost = dp[subState] + dp[state^subState] + length[subState] + length[state^subState] + abs(median[subState] - median[state^subState]);
                if (cost < dp[state]) {
                    dp[state] = cost;
                }
            }
            if ((state&(state-1)) != 0) {
                vector<int> numArr;
                int index = 0;
                int tmp = state;
                while (tmp > 0) {
                    if (tmp%2) {
                        for (int num:lists[index]) {
                            numArr.push_back(num);
                        }
                        length[state] += lists[index].size();
                    }
                    tmp /= 2;
                    index++;
                }
                sort(numArr.begin(), numArr.end());
                median[state] = numArr[(numArr.size()-1)/2];
            }
        }
        return dp[states-1];
    }
};


// use nth-element instead of sorting
// for (int subState = (state-1)&state; subState > 0; subState = (subState-1)&state) {}
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int N = lists.size();
        int states = pow(2, N);
        vector<long long> dp(states+1, LLONG_MAX), median(states+1, 0), length(states+1, 0);  // dp:minimum cost to merge into state

        for (int i=0; i<N; i++) {
            int state = pow(2, i);
            dp[state] = 0;
            length[state] = lists[i].size();
            median[state] = lists[i][(lists[i].size()-1)/2];
        }

        for (int state = 2; state < states; state++) {
            for (int subState = (state-1)&state; subState > 0; subState = (subState-1)&state) {
                long long cost = dp[subState] + dp[state^subState] + length[subState] + length[state^subState] + abs(median[subState] - median[state^subState]);
                if (cost < dp[state]) {
                    dp[state] = cost;
                }
            }
            if ((state&(state-1)) != 0 ) {
                vector<int> numArr;
                int index = 0;
                int tmp = state;
                while (tmp > 0) {
                    if (tmp%2) {
                        for (int num:lists[index]) {
                            numArr.push_back(num);
                        }
                        length[state] += lists[index].size();
                    }
                    tmp /= 2;
                    index++;
                }
                int midIdx = (numArr.size()-1)/2;
                nth_element(numArr.begin(), numArr.begin()+midIdx, numArr.end());
                median[state] = numArr[midIdx];
            }
        }

        return dp[states-1];
    }
};