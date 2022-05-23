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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        stack<ListNode*> pilha;
        ListNode* no = head;
        
        // Pela definição do problema, haverá ao menos um item na lista
        while (no != nullptr) {
            pilha.push (no);
            no = no->next;
        }
        
        // Pela definição do problema, n não está fora dos limites do tamanho da lista
        
        no = nullptr; // Para aproveitar variáveis
        
        while (!pilha.empty () && n > 0) {
            no = pilha.top ();
            pilha.pop ();
            n--;
        }
        
        if (pilha.empty ())
            head = no->next; // no é o próprio head, nesse caso
        else
            pilha.top ()->next = no->next;
                
        return head;
    }
};

