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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int contador = 1; // Ainda inexistente; base, o segundo da lista
        int primeiro = -1; // Idem
        int anterior = -1; // Idem
        int menor = -1; // Se não achar, será esse
        int maior = -1; // Idem
        while (head->next->next != nullptr) {
            if ((head->next->val < head->val && head->next->val < head->next->next->val) ||
               (head->next->val > head->val && head->next->val > head->next->next->val)) { // É um ponto crítico
                if (primeiro == -1) {
                    primeiro = contador;
                    anterior = contador;
                } else {
                    menor = (menor == -1 ? contador - primeiro : min (menor, contador - anterior));
                    maior = (maior == -1 ? contador - anterior : max (maior, contador - primeiro));
                    anterior = contador;
                }
            }
            head = head->next;
            contador += 1;
        }
        return {menor, maior};
    }
};

