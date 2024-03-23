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
    void reorderList(ListNode* head) {
        vector<ListNode*> tmp;
        while (head != nullptr) {
            tmp.push_back (head);
            head = head->next;
        }
        head = tmp [0]; // Reaproveita a variável head; há, pelo menos, um
        ListNode* percorrer = head;
        int i = 1, j = tmp.size () - 1; // Já começa do segundo, pois 0 já foi
        while (i <= j) {
            percorrer->next = tmp [j--]; // O topo já foi; começamos pelo segundo, no final
            percorrer = percorrer->next;
            if (i <= j) {
                percorrer->next = tmp [i++];
                percorrer = percorrer->next;
            }
        }
        percorrer->next = nullptr; // Fecha a lista
    }
};

