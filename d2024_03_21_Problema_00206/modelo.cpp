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
    ListNode* reverseList(ListNode* head) {
        deque<ListNode*> fila;
        fila.push_front (nullptr);
        while (head != nullptr) {
            fila.push_front (head);
            head = head->next;
        }
        head = fila.front ();
        fila.pop_front ();
        ListNode* tmp = head;
        while (!fila.empty ()) {
            tmp->next = fila.front ();
            tmp = tmp->next;
            fila.pop_front ();
        }
        return head;
    }
};

