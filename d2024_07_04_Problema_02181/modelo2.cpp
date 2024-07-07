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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* atual = head->next; // Já desconsidera o 1o zero
        while (atual != nullptr) {
            ListNode* proximo = atual->next;
            while (proximo->val != 0) {
                atual->val += proximo->val;
                proximo = proximo->next;
            }
            atual->next = proximo->next;
            atual = atual->next;
        }
        return head->next;
    }
};

