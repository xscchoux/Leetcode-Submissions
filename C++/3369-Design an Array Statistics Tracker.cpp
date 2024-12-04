using LL = long long;
class StatisticsTracker {
public:
    LL tot=0;
    unordered_map<int, int> numToCnt; // number : count
    map<int, set<int>> cnt;  // count : set of elements
    deque<int> numArr;
    // two multisets, upper.size() >= lower.size()
    multiset<int> upper;
    multiset<int, greater<>> lower;
    StatisticsTracker() {
        
    }
    void balance(multiset<int>& upper, multiset<int, greater<>>& lower) {
        if (lower.size() + 1 < upper.size()) {  // upper->lower
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        } else if (lower.size() > upper.size()) {    // lower->upper
            upper.insert(*lower.begin());
            lower.erase(lower.begin());
        }
    }

    void addNumber(int number) {
        tot += number;
        numArr.push_back(number);

        if (upper.empty() || number >= *upper.begin()) {
            upper.insert(number);
        } else {
            lower.insert(number);
        }
        balance(upper, lower);
        
        int count = numToCnt[number];
        numToCnt[number]++;
        if (cnt[count].contains(number)) {
            cnt[count].erase(number);
            if (cnt[count].size() == 0) {
                cnt.erase(count);
            }
        }
        cnt[count+1].insert(number);

    }
    
    void removeFirstAddedNumber() {
        int first = numArr.front();
        numArr.pop_front();

        tot -= first;
        if (first >= *upper.begin()) {
            upper.erase(upper.find(first));
        } else {
            lower.erase(lower.find(first));
        }
        balance(upper, lower);

        int count = numToCnt[first];
        numToCnt[first]--;
        cnt[count].erase(first);
        if (cnt[count].size() == 0) {
            cnt.erase(count);
        }
        if (count > 1) {
            cnt[count-1].insert(first);
        }
    }
    
    int getMean() {
        return tot/(numArr.size());
    }
    
    int getMedian() {
        return *upper.begin();
    }
    
    int getMode() {
        return *cnt.rbegin()->second.begin();
    }
};

/**
 * Your StatisticsTracker object will be instantiated and called as such:
 * StatisticsTracker* obj = new StatisticsTracker();
 * obj->addNumber(number);
 * obj->removeFirstAddedNumber();
 * int param_3 = obj->getMean();
 * int param_4 = obj->getMedian();
 * int param_5 = obj->getMode();
 */