class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0, drunk = 0;
        while (true) {
            if (numBottles > 0) {
                empty += numBottles;
                drunk += numBottles;
                numBottles = 0;
            } else if (empty >= numExchange) {
                empty -= numExchange;
                numBottles++;
                numExchange++;
            } else {
                break;
            }
        }
        return drunk;
    }
};