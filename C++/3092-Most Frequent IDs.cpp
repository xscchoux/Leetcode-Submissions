// two maps
using LL = long long;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        // solution 1: two maps
        int N = nums.size();
        unordered_map<int, LL> hmap;  // ID : frequency
        map<LL, int> freqCount; // frequency : count of IDs with this frequency
        vector<LL> res;
        
        for (int i=0; i<N; i++) {
            if (freqCount.count(hmap[nums[i]]) > 0) {
                freqCount[hmap[nums[i]]]--;
                if (freqCount[hmap[nums[i]]] == 0) freqCount.erase(hmap[nums[i]]);
            }
            hmap[nums[i]] += freq[i];
            freqCount[hmap[nums[i]]]++;
            res.push_back(freqCount.rbegin()->first);
        }
        
        return res;
    }
};

// priority queue, fastest
using LL = long long;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int N = nums.size();
        unordered_map<int, LL> hmap;       // ID : frequency
        priority_queue<pair<LL, int>> pq;  // {frequency, ID}
        vector<LL> res;
        
        for (int i=0; i<N; i++) {
            hmap[nums[i]] += freq[i];
            pq.push({hmap[nums[i]], nums[i]});
            while (!pq.empty() && hmap[pq.top().second] != pq.top().first) {  // remove {frequency, ID} not in the hmap
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        
        return res;
    }
};

// multiset
using LL = long long;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, LL> cnt;
        int N = nums.size();
        multiset<LL, greater<LL>> freqMs;
        vector<LL> res;
        cout << "here" << endl;
        for (int i=0; i<N; i++) {
            if (cnt[nums[i]] != 0) freqMs.erase(freqMs.find(cnt[nums[i]]));
            cnt[nums[i]] += freq[i];
            freqMs.insert(cnt[nums[i]]);
            // cout << *freqMs.begin() << endl;
            res.push_back(*freqMs.begin());
        }

        return res;
    }
};