/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *node){
        vector<int> left, right;
        Node* tmp = node;
        
        for (; tmp; right.push_back(tmp->val), tmp = tmp->next);

        tmp = node->prev;
        for (; tmp; left.push_back(tmp->val), tmp = tmp->prev);

        reverse(left.begin(), left.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};