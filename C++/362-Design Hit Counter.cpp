class HitCounter {
public:
    vector<int> stamp;
    HitCounter() {

    }
    
    void hit(int timestamp) {
        stamp.push_back(timestamp);    
    }
    
    int getHits(int timestamp) {
        auto it2 = upper_bound(begin(stamp), end(stamp), timestamp);
        auto it1 = lower_bound(begin(stamp), end(stamp), timestamp-299);      

        return it2-it1;
    }
};