class Solution {
public:
    vector<int> hours, minutes;
    void getHours(int hCount, int start, int val, vector<int>&arr) {
        if (hCount == 0) {
            arr.push_back(val);
            return;
        }
        for (int i=start; i<hours.size(); i++) {
            if (hours.size()-i < hCount || val + hours[i] > 11) break;
            getHours(hCount-1, i+1, val + hours[i], arr);
        }
    }
    void getMinutes(int mCount, int start, int val, vector<int>&arr) {
        if (mCount == 0) {
            arr.push_back(val);
            return;
        }
        for (int i=start; i<minutes.size(); i++) {
            if (minutes.size()-i < mCount || val + minutes[i] > 59) break;
            getMinutes(mCount-1, i+1, val + minutes[i], arr);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        // hour: 0~11, minutes: 0~59
        hours = {1, 2, 4, 8};
        minutes = {1, 2, 4, 8, 16, 32};
        vector<string> res;
        for (int hh=0; hh<=min(turnedOn, 4); hh++) {
            vector<int> currHour;
            getHours(hh, 0, 0, currHour);

            vector<int> currMinute;
            int mm = turnedOn - hh;

            getMinutes(mm, 0, 0, currMinute);

            for (int hour:currHour) {
                for (int minute:currMinute) {
                    string minuteString = to_string(minute);
                    if (minuteString.size() < 2) {
                        minuteString = "0" + minuteString;
                    }
                    string s = to_string(hour) + ":" + minuteString;
                    res.push_back(s);
                }
            }

        }
        sort(begin(res), end(res));
        return res;
    }
};