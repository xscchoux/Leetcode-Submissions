class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        stringstream start(loginTime);
        stringstream end(logoutTime);
        int hour1, minute1, hour2, minute2;
        char c;
        start >> hour1;
        start >> c;
        start >> minute1;

        end >> hour2;
        end >> c;
        end >> minute2;

        if (hour1*60+minute1 > hour2*60+minute2) {
            hour2 += 24;
        }

        vector<int> startTime = {0, 15, 30, 45, 60};
        if (find(startTime.begin(), startTime.end(), minute1) == startTime.end()) {
            auto it = lower_bound(startTime.begin(), startTime.end(), minute1);
            if (*it == 60) hour1++;
            minute1 = *it%60;
        }

        if (find(startTime.begin(), startTime.end(), minute2) == startTime.end()) {
            auto it = upper_bound(startTime.begin(), startTime.end(), minute2);
            it--;
            minute2 = *it;
        }

        int diffTime = hour2*60+minute2 - (hour1*60+minute1);
        diffTime = max(0, diffTime);

        return diffTime/15;
    }
};