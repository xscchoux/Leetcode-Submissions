// First AC
using PII = pair<int, int>;
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int durationCnt = 0;
        
        // for the last free time span

        // ------------------ LC 3439 ----------------------
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        int N = startTime.size(), res = 0, totDuration = 0;
        priority_queue<PII> pq;

        // similar to sliding window. Keep a window of k meetings
        int idx = 0;
        for (int i=0; i<N; i++) {
            if (durationCnt == 0) {
                res = max(res, startTime[i]);
            } else if (durationCnt <= 1){
                res = max(res, startTime[i] - totDuration);
            } else {
                totDuration -= (endTime[i-2] - startTime[i-2]);
                res = max(res, startTime[i] - endTime[i-2] - totDuration);
            }
            durationCnt++;
            totDuration += (endTime[i]-startTime[i]);
            if (i == 0) {
                pq.push({startTime[i], idx++});     
            } else {
                pq.push({startTime[i] - endTime[i-1], idx++});
            }
        }
        // -------------------------------------------------

        for (int i=0; i<N-1; i++) {
            int duration = endTime[i] - startTime[i];
            vector<PII> tmp;
            if (pq.top().first < duration) continue;

            // first pop
            if (pq.top().second == i || pq.top().second == i+1) {
                tmp.push_back(pq.top());
                pq.pop();
            } else if (pq.top().first >= duration) {
                res = max(res, startTime[i+1] - (i==0?0:endTime[i-1]) );
                continue;
            }

            // second pop
            if (pq.top().second == i || pq.top().second == i+1) {
                tmp.push_back(pq.top());
                pq.pop();
            } else if (!pq.empty() && pq.top().first >= duration){
                res = max(res, startTime[i+1] - (i==0?0:endTime[i-1]) );
                for (auto &p:tmp) {
                    pq.push(p);
                }
                continue;
            }

            if (!pq.empty() &&　pq.top().first >= duration) {
                res = max(res, startTime[i+1] - (i==0?0:endTime[i-1]) );
            }
            for (auto &p:tmp) {
                pq.push(p);
            }
        }

        return res;        
    }
};




// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/
// The implementation is challenging because managing indices in vectors can lead to errors
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gapArr;
        int N = startTime.size();
        gapArr.push_back(startTime[0]);

        for (int i=1; i<N; i++) {
            gapArr.push_back(startTime[i] - endTime[i-1]);
        }

        gapArr.push_back(eventTime-endTime[N-1]);

        vector<int> maxRightGap(gapArr.size(), 0);
        for (int i=gapArr.size()-1; i>=0; i--) {
            if (i == gapArr.size()-1) maxRightGap[i] = gapArr.back();
            else maxRightGap[i] = max(maxRightGap[i+1], gapArr[i]);
        }


        int maxGapLeft = 0, res = 0;
        for (int i=0; i<N; i++) {
            int currDuration = endTime[i] - startTime[i];
            if (currDuration <= max(maxGapLeft, i<N-1?maxRightGap[i+2]:0)) {
                res = max(res, gapArr[i] + currDuration + gapArr[i+1]);
            } else {
                res = max(res, gapArr[i] + gapArr[i+1]);
            }
            maxGapLeft = max(maxGapLeft, i>0?(startTime[i]-endTime[i-1]):startTime[i]);
        }

        return res;
    }
};