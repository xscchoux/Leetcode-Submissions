// sliding window with multiset
// prefix XOR + binary trie
struct TrieNode {
    TrieNode* children[2];
    int cnt;
    TrieNode(): cnt(0) {
        fill(begin(children), end(children), nullptr);
    }
};

class Solution {
public:
    void addNum(TrieNode* node, int num) {
        for (int i=15; i>=0; i--) {
            if (num & (1<<i)) {
                if (node->children[1] == nullptr) {
                    node->children[1] = new TrieNode();
                }
                node = node->children[1];
            } else {
                if (node->children[0] == nullptr) {
                    node->children[0] = new TrieNode();
                }
                node = node->children[0];                
            }
            node->cnt++;
        }
    }
    void deleteNum(TrieNode* node, int num) {
        for (int i=15; i>=0; i--) {
            if (num & (1<<i)) {
                node = node->children[1];
            } else {
                node = node->children[0];                
            }
            node->cnt--;
        }
    }

    int findMax(TrieNode* node, int currXOR) {
        int res = 0;
        for (int i=15; i>=0; i--) {
            if (currXOR & (1<<i)) {
                if (node->children[0] != nullptr && node->children[0]->cnt > 0) {
                    node = node->children[0];
                } else {
                    node = node->children[1];
                    res += (1<<i);
                }
            } else {
                if (node->children[1] != nullptr && node->children[1]->cnt > 0) {
                    node = node->children[1];
                    res += (1<<i);
                } else {
                    node = node->children[0];                                 
                }         
            }
        }
        return currXOR^res;
    }

    int maxXor(vector<int>& nums, int k) {
        int left = 0, N = nums.size();
        multiset<int> ms;
        TrieNode* root = new TrieNode();

        addNum(root, 0);
        int currXOR = 0, res = 0;

        vector<int> preXOR(N+1, 0);

        for (int i=0; i<N; i++) {
            ms.insert(nums[i]);
            currXOR = currXOR^nums[i];

            while (*ms.rbegin() - *ms.begin() > k) {
                ms.erase(ms.find(nums[left]));
                deleteNum(root, preXOR[left]);
                left++;
            }

            res = max(res, findMax(root, currXOR));

            preXOR[i+1] = currXOR;
            addNum(root, currXOR);
        }
        
        return res;
    }
};