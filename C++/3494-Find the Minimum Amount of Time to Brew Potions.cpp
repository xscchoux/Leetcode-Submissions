// First AC
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> endTime(n, 0);

        for (int i=0; i<m; i++) {
            long long timeCost = 0, currStart = 0;

            // determine current startTime
            for (int j=0; j<n; j++) {
                timeCost += skill[j]*mana[i];
                currStart = max(currStart, endTime[j] + skill[j]*mana[i] - timeCost);
            }

            timeCost = 0;
            for (int j=0; j<n; j++) {
                timeCost += skill[j]*mana[i];
                endTime[j] = currStart + timeCost;
            }
        }

        return endTime.back();
    }
};



class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> endTime(n, 0);

        for (int i=0; i<m; i++) {
            long long timeCost = 0, currStart = 0;

            // determine current startTime
            for (int j=0; j<n; j++) {
                currStart = max(currStart, endTime[j] - timeCost);
                timeCost += skill[j]*mana[i];
                endTime[j] = timeCost;
            }

            for (int j=0; j<n; j++) {
                endTime[j] += currStart;
            }
        }

        return endTime.back();
    }
};