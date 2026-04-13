class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        sort(begin(sides), end(sides));
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) return {};

        double angleA = acos((b*b+c*c-a*a)/(2*b*c))*180.0/M_PI;
        double angleB = acos((a*a+c*c-b*b)/(2*a*c))*180.0/M_PI;

        return {angleA, angleB, 180.0-angleA-angleB};

    }
};