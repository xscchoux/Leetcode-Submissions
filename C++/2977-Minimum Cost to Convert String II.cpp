using LL = long long;
struct TrieNode {
    TrieNode* children[26];
    int nodeId;
    explicit TrieNode():nodeId(-1){
        std::fill(children, children +26 , nullptr);
    }
    virtual ~TrieNode(){ // this makes code even faster
        for(TrieNode* e : children) delete e;
    }
};


class Solution {
public:
    void addString(TrieNode* node, string &s, int id) {
        int N = s.size();

        for (int i=N-1; i>=0; i--) {
            int c = s[i]-'a';
            if (node->children[c] == nullptr) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->nodeId = id;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int N = source.size();
        unordered_map<string, int> id2String;
        
        TrieNode* root = new TrieNode();

        // give an id for each string in original and changed
        int id = 0;
        for (int i=0; i<original.size(); i++) {
            if (!id2String.contains(original[i])) {
                addString(root, original[i], id);
                id2String[original[i]] = id;
                id++;
            }
            if (!id2String.contains(changed[i])) {
                addString(root, changed[i], id);
                id2String[changed[i]] = id;
                id++;
            }
        }

        id--;

        // floyd-warshall
        int stringCnt = id+1;
        vector<vector<LL>> dist(stringCnt, vector<LL>(stringCnt, LLONG_MAX/2));
        for (int i=0; i<stringCnt; i++) dist[i][i] = 0;

        for (int i=0; i<original.size(); i++) {
            int id1 = id2String[original[i]], id2 = id2String[changed[i]];
            dist[id1][id2] = min(dist[id1][id2], (LL)cost[i]);
        }

        for (int k=0; k<stringCnt; k++) {
            for (int i=0; i<stringCnt; i++) {
                for (int j=0; j<stringCnt; j++) {
                    if (i == j) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // dp[i] = min( dp[i] if source[i] == target[i], dp[j] + dist[id of source[j:i] if exists][id of target[j:i] if exists] )
        vector<LL> dp(N+1, LLONG_MAX/2);
        dp[0] = 0;

        for (int i=1; i<=N; i++) {
            if (source[i-1] == target[i-1]) {
                dp[i] = dp[i-1];
            }
            
            TrieNode* sourceNode = root, *targetNode = root;

            for (int j=i; j>=1; j--) {
                if (sourceNode->children[source[j-1]-'a'] == nullptr) break;
                sourceNode = sourceNode->children[source[j-1]-'a'];
                if (targetNode->children[target[j-1]-'a'] == nullptr) break;
                targetNode = targetNode->children[target[j-1]-'a'];
                if (targetNode->nodeId != -1 && sourceNode->nodeId != -1 && dp[j-1] != LLONG_MAX/2 && dist[sourceNode->nodeId][targetNode->nodeId] != (LLONG_MAX/2)) {
                    dp[i] = min(dp[i], dp[j-1] + dist[sourceNode->nodeId][targetNode->nodeId]);
                }                
            }
        }

        return dp.back() >= LLONG_MAX/2?-1:dp.back(); 
    }
};