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
private:
    int remover (ListNode* no, ListNode* ant, int n) {
        
        if (no == nullptr)
            return 0;
        
        int nivel = remover (no->next, no, n) + 1;
        
        if (nivel == n) {
            if (ant != nullptr) // Acabará sendo o 1o
                ant->next = no->next;
        }
        return nivel;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (remover (head, nullptr, n) == n)
            head = head->next; // O primeiro é que tem que ser removido
        return head;
    }
};

