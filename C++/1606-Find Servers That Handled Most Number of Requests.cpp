using PII = pair<int, int>;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int N = arrival.size();
        vector<int> cnt(k, 0);
        set<int> free;
        priority_queue<PII, vector<PII>, greater<>> pq;
        
        for (int i=0; i<k; i++) free.insert(i);

        for (int i=0; i<N; i++) {
            int currTime = arrival[i];
            while (!pq.empty() && currTime >= pq.top().first) {
                auto [t, index] = pq.top();
                pq.pop();
                free.insert(index);
            }
            if (!free.empty()) {
                auto it = free.lower_bound(i%k);
                int nxtIdx;
                if (it == free.end()) {
                    nxtIdx = *(free.begin());
                } else {
                    nxtIdx = *(it);
                }
                cnt[nxtIdx]++;
                free.erase(nxtIdx);
                pq.push({currTime + load[i], nxtIdx});
            }
        }
        
        vector<int> res;
        int maxCnt = *max_element(cnt.begin(), cnt.end());
        for (int i=0; i<k; i++) {
            if (cnt[i] == maxCnt) {
                res.push_back(i);
            }
        }
        return res;
    }
};


// Two priority queues. Modify the server index
using PII = pair<int, int>;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int N = arrival.size();
        vector<int> cnt(k, 0);
        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<PII, vector<PII>, greater<>> busy;
        
        for (int i=0; i<k; i++) free.push(i);

        for (int i=0; i<N; i++) {
            int currTime = arrival[i];
            while (!busy.empty() && currTime >= busy.top().first) {
                auto [t, serverIdx] = busy.top();
                busy.pop();
                int modifiedIdx = ((serverIdx - i) % k + k) % k + i; // makes the server index greater than i by N*k (N is an integer)
                // Unlike Python, (serverIdx - i) % k can be negative in C++, and also serverIdx-i can be less than -k. 
                free.push(modifiedIdx);
            }
            if (!free.empty()) {
                int nxtIdx = free.top()%k;
                free.pop();
                cnt[nxtIdx]++;
                busy.push({currTime + load[i], nxtIdx});
            }
        }

        vector<int> res;
        int maxCnt = *max_element(cnt.begin(), cnt.end());
        for (int i=0; i<k; i++) {
            if (cnt[i] == maxCnt) {
                res.push_back(i);
            }
        }
        return res;
    }
};