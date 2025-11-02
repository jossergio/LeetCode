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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* tmp = new ListNode (0, head);
        ListNode* ajudante = tmp;
        unordered_set consultar (nums.begin (), nums.end ());
        while (tmp->next != nullptr) {
            if (consultar.count (tmp->next->val) > 0) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return ajudante->next;
    }
};
