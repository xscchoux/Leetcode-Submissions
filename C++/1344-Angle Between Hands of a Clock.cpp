class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double hourDegree = hour*30 + 30*(minutes/60.0);
        double minuteDegree = minutes*6;
        double diff = abs(hourDegree-minuteDegree);

        return min(diff, 360.0-diff);

    }
};