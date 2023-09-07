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
        ListNode* ajudante = new ListNode (); // Será descartado ao final; para algoritmo
        ListNode* resposta = ajudante; // Se manterá fixo até o final
        ListNode * fim; // Será utilizado na função, para conter o final (início parte invertida)
        
        function<void ()> inverter = [&] () {
            if (right > 1) { // head nunca será nullptr, até aqui
                right -= 1; // Decrementa, pois será utilizado na recursão
                ListNode* tmp = head;
                head = head->next;
                inverter ();
                ajudante->next = tmp;
                ajudante = ajudante->next;
            } else {
                fim = head;
                ajudante->next = head;
                ajudante = ajudante->next;
                head = head->next;
            }
        };
        
        ListNode* anterior = nullptr;
        while (head != nullptr && left > 1) {
            anterior = head;
            ajudante->next = head;
            ajudante = ajudante->next;
            head = head->next;
            left -= 1;
            right -= 1; // right é referente à lista toda
        }
        inverter ();
        if (anterior == nullptr) {
            resposta->next = fim;
        } else {
            anterior->next = fim;
        }
        ajudante->next = head; // O que sobrou
        return resposta->next;
    }
};

