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
    ListNode* swapPairs(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            ListNode* seguinte = head->next;
            head->next = swapPairs (seguinte->next);
            seguinte->next = head;
            head = seguinte;
        }
        return head;
    }
};

