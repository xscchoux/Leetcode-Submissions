// First AC
class Solution {
public:
    bool smaller(vector<string> &tmp, vector<string> &res) {
        for (int i=0; i<tmp.size(); i++) {
            if (tmp[i] < res[i]) return true;
            else if (tmp[i] > res[i]) return false;
        }

        return false;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<string> res;
        int N = timestamp.size(), maxScore = 0;
        vector<tuple<int, string, string>> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({timestamp[i], username[i], website[i]});
        }
        sort(begin(arr), end(arr));

        for (int i=0; i<N; i++) {
            username[i] = get<1>(arr[i]);
            website[i] = get<2>(arr[i]);
        }

        unordered_map<string, vector<string>> hmap;
        for (int i=0; i<N; i++) {
            hmap[username[i]].push_back(website[i]);
        }

        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    int currScore = 0;
                    vector<string> tmp = {website[i], website[j], website[k]}; 
                    for (auto &[k, vec]:hmap) {
                        if (vec.size() < 3) continue;
                        int idx = 0;
                        for (auto &s:vec) {
                            if (tmp[idx] == s) {
                                idx++;
                            }
                            if (idx == 3) {
                                currScore++;
                                break;
                            }
                        }
                    }
                    if (currScore > maxScore || (currScore != 0 && currScore == maxScore && smaller(tmp, res) && !res.empty())) {
                        res = tmp;
                        maxScore = currScore;
                    }
                }
            }
        }

        return res;      
    }
};


// Much faster
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int N = username.size();
        unordered_map<string, map<int, string>> hmap;
        unordered_map<string, int> patternCnt;

        for (int i=0; i<N; i++) {
            hmap[username[i]][timestamp[i]] = website[i];
        }

        for (auto it = begin(hmap); it != end(hmap); it++) {
            unordered_set<string> patternFound;
            for (auto it1=begin(it->second); it1 != end(it->second); it1++) {
                for (auto it2=next(it1); it2 != end(it->second); it2++) {
                    for (auto it3=next(it2); it3 != end(it->second); it3++) {
                        string patternString = it1->second + "$" + it2->second + "#" + it3->second;
                        if (!patternFound.count(patternString)) {
                            patternFound.insert(patternString);
                            patternCnt[patternString]++;
                        }
                    }
                }
            }
        }

        string patternString;
        int maxCount = 0;
        for (auto &[k, v]:patternCnt) {
            if (v > maxCount) {
                maxCount = v;
                patternString = k;
            } else if (v == maxCount) {
                patternString = min(k, patternString);
            }
        }

        auto i1 = patternString.find("$"), i2 = patternString.find("#");

        return {patternString.substr(0, i1), patternString.substr(i1+1, i2-i1-1), patternString.substr(i2+1)};

    }
};