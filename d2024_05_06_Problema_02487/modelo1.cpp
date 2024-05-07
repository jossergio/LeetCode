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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> pilha;
        while (head != nullptr) {
            pilha.push (head);
            head = head->next;
        }
        head = pilha.top (); // O último sempre fica
        pilha.pop ();
        while (!pilha.empty ()) {
            ListNode* tmp = pilha.top ();
            pilha.pop ();
            if (tmp->val >= head->val) {
                tmp->next = head;
                head = tmp;
            }
        }
        return head;
    }
};

