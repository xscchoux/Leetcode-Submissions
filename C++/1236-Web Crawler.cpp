/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string getHostName(string& s) {

        int endPos = min(s.size(), s.find('/', 7));

        return s.substr(7, endPos-7);
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        // string hostname = "";
        int N = startUrl.size();

        queue<string> q;
        string hostname = getHostName(startUrl);
        q.push(startUrl);
        unordered_set<string> visited{startUrl}; 

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (string nxt:htmlParser.getUrls(curr)) {
                if (!visited.contains(nxt) && hostname == getHostName(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        return vector<string>(begin(visited), end(visited));
    }
};