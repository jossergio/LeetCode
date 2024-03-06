/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* rapido = head;
        ListNode* lento = head;
        while (lento != nullptr && rapido != nullptr && rapido->next != nullptr) {
            rapido = rapido->next->next;
            lento = lento->next;
            if (rapido == lento) // Por lógica, nunca serão nullptr ao mesmo tempo
                return true; // Ambos são o mesmo nó
        }
        return false; // Encontrou um fim; não é cíclico
    }
};

