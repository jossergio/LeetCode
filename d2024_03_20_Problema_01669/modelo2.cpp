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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ultimo = list2;
        while (ultimo->next != nullptr) // Há, pelo menos, um
            ultimo = ultimo->next;
        ListNode* correr = list1;
        ListNode *primeiro = nullptr, *segundo = nullptr; // Conterão o primeiro e o segundo elemntos da lista
        int contar = 1;
        while (b >= 0) {
            if (contar == a)
                primeiro = correr;
            if (contar == b + 1) // Tem que ser o próximo...
                segundo = correr->next; // .. do próximo
            a -= 1;
            b -= 1;
            correr = correr->next;
        }
        primeiro->next = list2;
        ultimo->next = segundo;
        return list1; // Só é possível assim porque o primeiro nunca é eliminado
    }
};

