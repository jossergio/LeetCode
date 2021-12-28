/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr; // LeeCode
        ListNode *c = head;
        int cont = 0;
        while (c != nullptr) {
            cont++;
            c = c->next;
        }
        cont = cont / 2;
        c = head;
        while (cont > 0) {
            cont--;
            c = c->next;
        }
        return c;
    }
};

