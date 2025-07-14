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
    int getDecimalValue(ListNode* head) {
        int resposta = 0;
        ListNode *no = head;
        while (no != nullptr) {
            resposta <<= 1;
            resposta |= no->val;
            no = no->next;
        } // while
        return resposta;
    }
};
