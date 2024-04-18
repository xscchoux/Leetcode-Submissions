using LL = long long;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // weighted prefix sum
        // x1  x2  x3  x4
        //   d1  d2  d3
        // x1: left prefix:0, right prefix: 3*d1 + 2*d2 + d3
        // x2: left prefix:d1, right prefix: 2*d2 + d3
        // x3: left prefix:d1 + 2*d2, right prefix: d3
        // x4: left prefix: d1 + 2*d2 + 3*d3

        int N = nums.size();
        vector<LL> res(N, 0);
        unordered_map<int, vector<int>> hmap;


        for (int i=0; i<N; i++) {
            hmap[nums[i]].push_back(i);
        }
        
        for (auto &kv:hmap) {
            LL tot = 0;
            int cnt = 1;
            for (int i=1; i<kv.second.size(); i++) {
                tot += cnt*(kv.second[i]-kv.second[i-1]);
                res[kv.second[i]] += tot;
                cnt++;
            }
        }
        
        unordered_map<int, vector<int>> hmap2;
        for (int i=N-1; i>=0; i--) {
            hmap2[nums[i]].push_back(i);
        }
        
        for (auto &kv:hmap2) {
            LL tot = 0;
            int cnt = 1;
            for (int i=1; i<kv.second.size(); i++) {
                tot += cnt*(kv.second[i-1]-kv.second[i]);
                res[kv.second[i]] += tot;
                cnt++;
            }
        }        

        return res;
    }
};