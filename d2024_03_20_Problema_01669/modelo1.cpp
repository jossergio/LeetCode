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
        ListNode* ponta = new ListNode (0, list1);
        ListNode* correr = ponta;
        ListNode* ultimo = list2;
        while (ultimo->next != nullptr) // Há, pelo menos, um
            ultimo = ultimo->next;
        while (a > 0) {
            a -= 1;
            b -= 1;
            correr = correr->next;
        }
        ListNode* correr2 = correr;
        b += 1; // Pois tinha tirado no anterior
        while (b >= 0) {
            correr2 = correr2->next;
            b -= 1;
        }
        correr->next = list2;
        ultimo->next = correr2;
        return ponta->next;
    }
};

