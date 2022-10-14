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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) // Só ter um elemento é um caso especial
            return nullptr; // O único elemento é retirado
        ListNode *rapido = head, *devagar = head;
        while (rapido) {
            rapido = rapido->next;
            if (rapido) {
                rapido = rapido->next; // Produz um duplo salto
                if (rapido && rapido->next) {
                    devagar = devagar->next;
                }
            }
        }
        devagar->next = devagar->next->next; // Salta o próximo elemento, tirando-o da lista
        return head;
    }
};

