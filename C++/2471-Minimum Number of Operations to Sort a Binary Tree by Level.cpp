// use an unordered_map and two vectors, not efficient enough

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while (!q.empty()) {
            int length = q.size();
            unordered_map<int, int> hmap; // val:pos
            vector<int> vec;
            int ind = 0;
            while (length-- > 0) {
                auto curr = q.front();
                vec.push_back(curr->val);
                hmap[curr->val] = ind++;
                q.pop();
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            vector<int> tmp = vec;
            sort(begin(tmp), end(tmp));
            for (int i=0; i<vec.size(); i++) {
                if (tmp[i] != vec[i]) {
                    int correctIdx = hmap[tmp[i]];
                    swap(hmap[vec[i]], hmap[tmp[i]]);
                    swap(vec[i], vec[correctIdx]);
                    res++;
                }
            }
        }
        return res;
    }
};

// Clever but kinda hard to understand
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> idx(sz);
            iota(begin(idx), end(idx), 0);
            vector<int> arr;
            while (sz-- > 0) {
                TreeNode* curr = q.front();
                q.pop();
                arr.push_back(curr->val);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            sort(begin(idx), end(idx), [&](int a, int b) {
                return arr[a] < arr[b];
            });

            // put all items in idx to the correct index. Ex: [2,3,1,0] -> [0,1,2,3]
            for (int i=0; i<arr.size();) {
                if (i != idx[i]) {
                    swap(idx[i], idx[idx[i]]);
                    res++;
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};