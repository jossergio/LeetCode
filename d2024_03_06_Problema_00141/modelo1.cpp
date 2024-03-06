/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) // LeetCode pode mandar vazio
            return false;
        ListNode* rapido = head;
        ListNode* lento = head;
        while (true) { // Um laço infinito
            if (rapido->next == nullptr)
                return false;
            rapido = rapido->next->next;
            lento = lento->next;
            if (lento == nullptr || rapido == nullptr)
                return false;
            if (lento == rapido)
                return true;
        }
        return false; // Só para ter algo aqui
    }
};

