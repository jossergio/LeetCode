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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> lista;
        while (head != nullptr) {
            lista.push_back (head);
            head = head->next;
        }
        vector<ListNode*> resposta (k, nullptr);
        int quociente = lista.size () / k;
        int resto = lista.size () % k;
        auto ponteiro = lista.begin ();
        int iLista = 0;
        while (ponteiro != lista.end ()) {
            ListNode* tmp = new ListNode (0, nullptr);
            ListNode* proximo = tmp;
            for (int i = 0; i < quociente; i += 1) { // Sepre haverá algum
                proximo->next = *ponteiro;
                proximo = proximo->next;
                ponteiro++;
            }
            if (resto > 0) { // Acrescenta um, das sobras
                resto -= 1;
                proximo->next = *ponteiro;
                proximo = proximo->next;
                ponteiro++; 
            }
            proximo->next = nullptr; // Acrescenta ao trecho
            resposta [iLista++] = tmp->next; // Descarta o primeiro, aseado no algoritmo
        }
        return resposta;
    }
};

