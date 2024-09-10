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
    int mdc (int a, int b) {
        if (a < b) swap (a, b);
        for (int d = b; d > 1; d -= 1) {
            if (a % d == 0 && b % d == 0) return d;
        }
        return 1;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            ListNode* inserir = new ListNode (mdc (head->val, head->next->val), head->next);
            head->next = inserir;
            inserir->next = insertGreatestCommonDivisors (inserir->next);
        }
        return head;
    }
};

