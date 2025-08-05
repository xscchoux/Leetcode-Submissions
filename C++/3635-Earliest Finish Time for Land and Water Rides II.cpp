// My solution, O(nlogn), map + binary search
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        vector<pair<int, int>> landArr;
        for (int i=0; i<landStartTime.size(); i++) {
            landArr.push_back({landStartTime[i], landDuration[i]});
        }

        sort(begin(landArr), end(landArr), [] (auto a, auto b) {
            return (a.first < b.first) || (a.first == b.first && a.second < b.second);
        });

        vector<pair<int, int>> waterArr;
        for (int i=0; i<waterStartTime.size(); i++) {
            waterArr.push_back({waterStartTime[i], waterDuration[i]});
        }

        sort(begin(waterArr), end(waterArr), [] (auto a, auto b) {
            return (a.first < b.first) || (a.first == b.first && a.second < b.second);
        });

        // Calculate the minimum duration for each landStartTime[i]
        map<int, int> hmap1;
        int duration = INT_MAX;
        for (int i=0; i<landArr.size(); i++) {
            if (i > 0 && landArr[i].first == landArr[i-1].first) continue;
            duration = min(duration, landArr[i].second);
            hmap1[landArr[i].first] = duration;
        }

        // Calculate the minimum time the land ride ends for time >= landStartTime[i]
        int minlandEndTime = INT_MAX;
        for (auto it = rbegin(hmap1); it != rend(hmap1); it++) {
            minlandEndTime = min(minlandEndTime, it->first + it->second);
            hmap1[it->first] = minlandEndTime;
        }

        // Calculate the minimum duration for each waterStartTime[i]
        map<int, int> hmap2;
        duration = INT_MAX;
        for (int i=0; i<waterArr.size(); i++) {
            if (i > 0 && waterArr[i].first == waterArr[i-1].first) continue;
            duration = min(duration, waterArr[i].second);
            hmap2[waterArr[i].first] = duration;
        }

        // Calculate the minimum time the water ride ends for time >= waterStartTime[i]
        int waterFarthest = INT_MAX;
        for (auto it = rbegin(hmap2); it != rend(hmap2); it++) {
            waterFarthest = min(waterFarthest, it->first + it->second);
            hmap2[it->first] = waterFarthest;
        }

        // land ride then water ride
        int res = INT_MAX;
        for (auto &[start, endTime]:hmap1) {
            auto it = hmap2.lower_bound(endTime);
            if (it != hmap2.end()) {
                res = min(res, it->second);            
            }

            if (it != begin(hmap2)) {
                it--;
                res = min(res, endTime + (it->second-it->first) );
            }

        }

        // water ride then land ride
        for (auto &[start, endTime]:hmap2) {
            auto it = hmap1.lower_bound(endTime);
            if (it != hmap1.end()) {
                res = min(res, it->second);
            }            
            if (it != begin(hmap1)) {
                it--;
                res = min(res, endTime + (it->second - it->first));
            }
        }

        return res;
    }
};


// O(n), really clever
// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/solutions/7036574/java-c-python-straight-forward-solution/
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minLandEndTime = INT_MAX;
        for (int i=0; i<landStartTime.size(); i++) {
            minLandEndTime = min(minLandEndTime, landStartTime[i] + landDuration[i]);
        }

        int minWaterEndTime = INT_MAX, landWater = INT_MAX;
        for (int i=0; i<waterStartTime.size(); i++) {
            minWaterEndTime = min(minWaterEndTime, waterStartTime[i] + waterDuration[i]);
            landWater = min(landWater, max(minLandEndTime, waterStartTime[i]) + waterDuration[i]);
        }

        int waterLand = INT_MAX;
        for (int i=0; i<landStartTime.size(); i++) {
            waterLand = min(waterLand, max(minWaterEndTime, landStartTime[i]) + landDuration[i]);
        }

        return min(waterLand, landWater);
    }
};