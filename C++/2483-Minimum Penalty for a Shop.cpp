class Solution {
public:
    int bestClosingTime(string customers) {
        int currP = count(customers.begin(), customers.end(), 'Y'), minP = currP;
        int res = 0;
        for (int i=0; i<customers.size(); i++) {
            currP += customers[i] == 'Y'?-1:1;
            if (currP < minP) {
                res = i+1;
                minP = currP;
            }
        }
        return res;
    }
};


// Better, no need to calculate total penalty first
class Solution {
public:
    int bestClosingTime(string customers) {
        int currP = 0, minP = currP;
        int res = 0;
        for (int i=0; i<customers.size(); i++) {
            currP += customers[i] == 'Y'?-1:1;
            if (currP < minP) {
                res = i+1;
                minP = currP;
            }
        }
        return res;
    }
};