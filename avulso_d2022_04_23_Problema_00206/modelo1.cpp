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
protected:
    ListNode* reverter (ListNode* ant, ListNode* no) {
        if (no == nullptr)
            return ant;
        ListNode* tmp = reverter (no, no->next);
        no->next = ant;
        return tmp;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverter (nullptr, head);
    }
};

