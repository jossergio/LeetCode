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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // Fiz um modelo com inversão das listas. Mas, os testes indicaram
        // isso, de que as listas foramm modificadas em suas estruturas
        
        stack<ListNode*> pilhaA;
        stack<ListNode*> pilhaB;
        
        ListNode* tmp = headA;
        
        // Gera a pilha de A
        while (tmp != nullptr) {
            pilhaA.push (tmp);
            tmp = tmp->next;
        }

        tmp = headB;
        
        // Gera a pilha de B
        while (tmp != nullptr) {
            pilhaB.push (tmp);
            tmp = tmp->next;
        }
        
        ListNode* resposta = nullptr; // Por definição
        
        while (!(pilhaA.empty () || pilhaB.empty ())) {
            if (pilhaA.top () != pilhaB.top ()) // Melhor ficar aqui que no teste do laço
                return resposta; // É o anterior igual, se existir, ou nullptr, se ainda não
            resposta = pilhaA.top (); // Tanto faz
            pilhaA.pop ();
            pilhaB.pop ();
        }
        
        return resposta; // Só deve chegar aqui se for o primeiro de uma das duas listas
    }
};

