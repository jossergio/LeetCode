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
        if (!head || !head->next)
            return head;
        ListNode* impar = new ListNode (0); // Esse 1o será descartado
        ListNode* cabImpar = impar;
        ListNode* par = new ListNode (0); // Idem
        ListNode* cabPar = par;
        while (head) {
            impar->next = head;
            impar = impar->next;
            if (head->next) {
                head = head->next;
                par->next = head;
                par = par->next;
            }
            head = head->next;
        }
        par->next = nullptr; // Fecha a fila
        impar->next = cabPar->next;
        return cabImpar->next;
    }
};

