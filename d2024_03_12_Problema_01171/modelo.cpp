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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* ponta = new ListNode (0, head); // Adiciona um auxiliar
        ListNode* inicio = ponta;
        while (inicio != nullptr) {
            ListNode* final = inicio->next;
            int acumulado = 0;
            while (final != nullptr) {
                acumulado += final->val;
                if (acumulado == 0) {
                    inicio->next = final->next;
                }
                final = final->next;
            }
            inicio = inicio->next;
        }
        return ponta->next;
    }
};

