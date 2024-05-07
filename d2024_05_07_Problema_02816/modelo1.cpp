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
    ListNode* doubleIt(ListNode* head) {
        stack<int> pilha;
        while (head != nullptr) {
            pilha.push (head->val);
            head = head->next;
        }
        int vaiUm = 0;
        while (!pilha.empty ()) {
            int tmp = 2 * pilha.top () + vaiUm;
            pilha.pop ();
            head = new ListNode (tmp % 10, head);
            vaiUm = tmp / 10;
        }
        if (vaiUm > 0)
            head = new ListNode (vaiUm, head);
        return head;
    }
};

