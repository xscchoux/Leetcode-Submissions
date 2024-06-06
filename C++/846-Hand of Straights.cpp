class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();
        if (N%groupSize != 0) return false;

        map<int, int> hmap;
        for (int num:hand) {
            hmap[num]++;
        }

        for (int i=0; i < N/groupSize; i++ ){
            int firstKey = hmap.begin()->first;
            for (int j=firstKey; j<firstKey+groupSize; j++) {
                if (hmap.find(j) == hmap.end()) return false;
                hmap[j]--;
                if (hmap[j] == 0) {
                    hmap.erase(j);
                }
            }
        }

        return true;
    }
};