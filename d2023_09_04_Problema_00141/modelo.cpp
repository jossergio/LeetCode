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
        set<ListNode*> passou;
        while (head != nullptr) {
            if (passou.count (head) > 0)
                return true;
            passou.insert (head);
            head = head->next;
        }
        return false;
    }
};

