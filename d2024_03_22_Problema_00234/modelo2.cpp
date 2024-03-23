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
    bool isPalindrome(ListNode* head) {
        stack<int> pilha;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            pilha.push (tmp->val);
            tmp = tmp->next;
        }
        while (head != nullptr) {
            if (head->val != pilha.top ())
                return false;
            // else
            pilha.pop ();
            head = head->next; // pilha e head têm o mesmo tamanho
        }
        return true; // Passou em todos os testes
    }
};

