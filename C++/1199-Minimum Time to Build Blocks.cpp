class Solution {
public:
    int N;
    int dfs(int idx, vector<int>& blocks, int split, int num, vector<vector<int>>& memo){
        if (idx == N) return 0;
        if (num == 0) return INT_MAX;
        if (N-idx <= num) return blocks[idx];
        if (memo[idx][num] != -1) return memo[idx][num];
        
        int res = INT_MAX;
        // split
        res = split + dfs(idx, blocks, split, min(N, num*2), memo);
        // no split
        res = min(res, max(blocks[idx], dfs(idx+1, blocks, split, num-1, memo)));
        memo[idx][num] = res;
        return res;
    }
    
    int minBuildTime(vector<int>& blocks, int split) {
        this->N = blocks.size();
        if (N == 1) return blocks[0];
        sort(blocks.begin(), blocks.end(), greater<int>());
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return dfs(0, blocks, split, 1, memo);
    }
};

// priority queue, very hard to come up with
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (int b:blocks) {
            pq.push(b);
        }

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            pq.push(split + max(first, second));
        }

        return pq.top();
    }
};