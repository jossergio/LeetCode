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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* cabecaImpar = nullptr;
        ListNode* proximoImpar = nullptr;
        ListNode* cabecaPar = nullptr;
        ListNode* proximoPar = nullptr;
        int indice = 1; // 1-based
        while (head) {
            if (indice % 2) { // resto == 1; ímpar
                if (!cabecaImpar) { // nullptr
                    cabecaImpar = proximoImpar = head;
                } else {
                    proximoImpar->next = head;
                    proximoImpar = proximoImpar->next;
                }
            } else { // % 2
                if (!cabecaPar) { // nullptr
                    cabecaPar = proximoPar = head;
                } else {
                    proximoPar->next = head;
                    proximoPar = proximoPar->next;
                }
            }
            head = head->next;
            indice += 1;
        }
        if (proximoPar) // not nullptr
            proximoPar->next = nullptr; // Fecha a lista geral
        if (proximoImpar) // not nullptr
            proximoImpar->next = cabecaPar; // mesmo se nullptr
        else
            proximoImpar = cabecaPar; // Mesmo se nullptr
        return cabecaImpar;
    }
};

