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
        ListNode *rapido = head, *lento = head;
        while (rapido != nullptr && rapido->next != nullptr) {
            rapido = rapido->next->next;
            lento = lento->next;
        }
        return lento;
    }
};

