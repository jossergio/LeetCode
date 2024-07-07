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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* resposta = new ListNode (0);
        ListNode* proximo = resposta;
        head = head->next; // Para tirar o 1o zero
        while (head != nullptr) {
            int valor = 0;
            while (head->val != 0) { // Termina com um nó de valor zero
                valor += head->val;
                head = head->next;
            }
            head = head->next; // Tira o zero atual
            proximo->next = new ListNode (valor);
            proximo = proximo->next;
        }
        return resposta->next;
    }
};

