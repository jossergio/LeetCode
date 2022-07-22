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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        stack<ListNode*> pilha;
        
        ListNode* ajudante = new ListNode (0); // Será descartado ao final; facilitador
        ListNode* sequenciador = ajudante;
        
        while (head && left > 1) { // Obs.: 1-begin
            sequenciador->next = head;
            sequenciador = sequenciador->next;
            head = head->next;
            left--;
            right--;
        }
        
        while (head && right > 0) { // 1-begin; mas, já vem descontado o anterior
            pilha.push (head);
            head = head->next;
            right--;
        }
        
        while (!pilha.empty ()) {
            sequenciador->next = pilha.top ();
            pilha.pop ();
            sequenciador = sequenciador->next;
            if (!pilha.empty ())
                sequenciador->next = pilha.top ();
        }
        
        sequenciador->next = head;
        return ajudante->next;
    }
};

