using PIL = pair<int, long long>;
class ExamTracker {
public:
    vector<PIL> arr;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        if (!arr.empty()) {
            arr.push_back({time, arr.back().second + score});
        } else {
            arr.push_back({time, score});
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it2 = upper_bound(begin(arr), end(arr), make_pair(endTime, LLONG_MAX));
        auto it1 = lower_bound(begin(arr), end(arr), make_pair(startTime, 0LL));
        long long score2, score1;
        if (it1 == begin(arr)) {
            score1 = 0;
        } else {
            it1 = prev(it1);
            score1 = it1->second;
        }

        if (it2 == begin(arr)) {
            score2 = 0;
        } else {
            it2 = prev(it2);
            score2 = it2->second;
        }
        
        return score2-score1;
    }
};


// Another way
using PIL = pair<int, long long>;
class ExamTracker {
public:
    vector<PIL> arr;
    ExamTracker() {
        arr.emplace_back(0, 0);
    }
    
    void record(int time, int score) {
        if (!arr.empty()) {
            arr.emplace_back(time, arr.back().second + score);
        } else {
            arr.emplace_back(time, score);
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it2 = upper_bound(begin(arr), end(arr), make_pair(endTime, LLONG_MAX));
        auto it1 = lower_bound(begin(arr), end(arr), make_pair(startTime, 0LL));

        it1 = prev(it1);
        long long score1 = it1->second;

        it2 = prev(it2);
        long long score2 = it2->second;
        
        return score2-score1;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */