// Time:  O(N! * N * K), N! : all permutations of nums, N: length of nums, K: length of pre
// Space: O(N! * N)    , we have N! permutations and each requries N space

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        vector<int> target = nums;
        sort(begin(target), end(target));
        if (nums == target) return 0;

        unordered_set<vector<int>, VectorHash> visited;
        queue<vector<int>> q;

        q.push(nums);
        visited.insert(nums);
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                vector<int> curr = q.front();
                q.pop();

                if (curr == target) return step;

                for (int i=0; i<pre.size(); i++) {
                    vector<int> nxt = curr;
                    reverse(begin(nxt), begin(nxt)+pre[i]);
                    if (!visited.contains(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            step++;
        }

        return -1;
    }
};





public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        string target = "", numString = "";
        for (int i=0; i<nums.size(); i++) {
            target += (i + '0');
            numString += (nums[i] + '0');
        }

        if (numString == target) return 0;

        unordered_set<string> visited;
        queue<string> q;

        q.push(numString);
        visited.insert(numString);
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                string curr = q.front();
                q.pop();

                if (curr == target) return step;

                for (int i=0; i<pre.size(); i++) {
                    string nxt = curr;
                    reverse(begin(nxt), begin(nxt)+pre[i]);
                    if (!visited.contains(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            step++;
        }

        return -1;
    }
};