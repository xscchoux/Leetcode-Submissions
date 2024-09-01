/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* res = dummy;

        while (poly1 != NULL && poly2 != NULL) {
            PolyNode* tmp1 = poly1;
            PolyNode* tmp2 = poly2;
            if (tmp1->power > tmp2->power) {
                res->next = poly1;
                res = res->next;
                poly1 = poly1->next;
            } else if (tmp2->power > tmp1->power) {
                res->next = poly2;
                res = res->next;
                poly2 = poly2->next;
            } else {
                int c1 = tmp1->coefficient, c2 = tmp2->coefficient;
                if (c1 + c2 != 0) {
                    res->next = new PolyNode(c1+c2, tmp1->power);
                    res = res->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        if (poly1 == nullptr) {
            res->next = poly2;
        } else {
            res->next = poly1;
        }

        return dummy->next;
    }
};