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
        queue<ListNode*> fila;
        ListNode* tmp = head;
        while (tmp) {
            fila.push (tmp);
            tmp = tmp->next;
        }
        int limite = fila.size () / 2; // Divisão inteira
        if (!limite) // != 0; só teria um elemento; não tem próximo, para linkar
            return nullptr; // Retorna logo
        while (limite) { // != 0    
            tmp = fila.front (); // Reutiliza a variável; manterá o anterior, que sera tirado da fila
            fila.pop (); // Basta tirar; não faz nada na pilha
            limite -= 1;
        }
        if (!fila.empty ())
            tmp->next = fila.front ()->next;
        // Não precisa fazer mais nada na fila; nem esvaziar
        return head;
    }
};

