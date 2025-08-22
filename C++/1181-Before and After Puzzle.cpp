// first AC
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, unordered_set<string>> endMap, startMap;
        unordered_set<string> res;
        for (auto &s:phrases) {
            int idx = 0;
            string head = "";
            while (idx < s.size() && s[idx] != ' ') {
                head += s[idx++];
            }

            if (endMap.contains(head)) {
                for (auto it=endMap[head].begin(); it != endMap[head].end(); it++) {
                    res.insert(((*it).size() > 0?(*it + " "):"") + head + (idx>=s.size()?"": (" " + s.substr(idx+1))) );
                }
            }

            int endIdx = s.size()-1;
            string endWord = "";
            while (endIdx >= 0 && s[endIdx] != ' ') {
                endIdx--;
            }
            endWord = s.substr(endIdx+1);

            if (startMap.contains(endWord)) {
                for (auto it=startMap[endWord].begin(); it != startMap[endWord].end(); it++) {
                    res.insert((endIdx < 0? "":(s.substr(0, endIdx)) + " ") + endWord + ((*it).size() > 0?(" " + *it):"") );
                }
            }

            startMap[head].insert( idx>=s.size()?"":s.substr(idx+1));
            endMap[endWord].insert(endIdx < 0? "":s.substr(0, endIdx));
        }

        vector<string> ans(begin(res), end(res));
        sort(begin(ans), end(ans));
        
        return ans;
    }
};


// use find() and rfind(), better
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, set<string>> startMap, endMap;
        set<string> res;
        for (auto &s:phrases) {
            auto firstEnd = s.find(' '), lastStart = s.rfind(' ');
            firstEnd = firstEnd == string::npos?s.size():firstEnd;
            lastStart  = lastStart == string::npos?0:lastStart+1;
            string firstWord = s.substr(0, firstEnd), endWord = s.substr(lastStart);

            if (endMap.contains(firstWord)) {
                for (auto &endPart:endMap[firstWord]) {
                    res.insert(endPart + s);
                }
            }

            if (startMap.contains(endWord)) {
                for (auto &startPart:startMap[endWord]) {
                    res.insert(s + startPart);
                }
            }
            startMap[firstWord].insert(s.substr(firstEnd));
            endMap[endWord].insert(s.substr(0, lastStart));

        }

        return vector<string>(begin(res), end(res));
    }
};