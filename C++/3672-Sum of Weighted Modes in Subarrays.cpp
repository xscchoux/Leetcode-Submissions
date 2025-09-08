// Two maps, slow
class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        map<int, set<int>, greater<>> freqMap;
        unordered_map<int, int> cnt;
        long long res = 0;
        int N = nums.size();

        for (int i=0; i<N; i++) {
            if (cnt.contains(nums[i])) {
                int originalFreq = cnt[nums[i]];
                freqMap[originalFreq].erase(nums[i]);
                if (freqMap[originalFreq].empty()) {
                    freqMap.erase(originalFreq);
                }
                freqMap[originalFreq+1].insert(nums[i]);
            } else {
                freqMap[1].insert(nums[i]);
            }
            
            cnt[nums[i]]++;

            if (i >= k) {
                int prev = nums[i-k];
                int originalFreq = cnt[prev];
                freqMap[originalFreq].erase(prev);
                if (freqMap[originalFreq].empty()) {
                    freqMap.erase(originalFreq);
                }
                if (originalFreq-1 > 0) {
                    freqMap[originalFreq-1].insert(prev);
                }
                cnt[prev]--;
            }

            if (i >= k-1) {
                res += (long long)(begin(freqMap)->first)*(*(begin((begin(freqMap)->second))));
            }
        }
        return res;
    }
};


// Fast clever priority queue solution
using PII = pair<int, int>;
class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        priority_queue<PII> pq;
        unordered_map<int, int> cnt;
        long long res = 0;

        for (int i=0; i<k-1; i++) {
            pq.push({++cnt[nums[i]], -nums[i]});
        }

        for (int i=k-1; i<nums.size(); i++) {
            pq.push({++cnt[nums[i]], -nums[i]});

            while (!pq.empty()) {
                auto [freq, minusVal] = pq.top();
                
                if (cnt[-minusVal] != freq) {  // frequency in cnt is always correct
                    pq.pop();
                    continue;
                }  
                res += (long long)freq*(-minusVal);
                break;
            }

            pq.push({--cnt[nums[i-k+1]], -nums[i-k+1]});
        }

        return res;
    }
};