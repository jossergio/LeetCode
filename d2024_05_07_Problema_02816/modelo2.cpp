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
    void dobro (ListNode* no) {
        no->val *= 2;
        if (no->next != nullptr) {
            dobro (no->next);
            no->val += no->next->val / 10;
            no->next->val %= 10;
        }
    }
public:
    ListNode* doubleIt(ListNode* head) {
        dobro (head);
        if (head->val >= 10)
        {
            head = new ListNode {head->val / 10, head};
            head->next->val %= 10;
        }
        return head;
    }
};

