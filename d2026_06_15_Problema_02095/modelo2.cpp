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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *devagar = head, *rapido = head, *ant = nullptr;
        while (rapido != nullptr && rapido->next != nullptr) {
            rapido = rapido->next->next;
            ant = devagar;
            devagar = devagar->next;
        }
        if (ant == nullptr) {
            head = nullptr; // Só tinha um
        } else {
            ant->next = devagar->next;
        }
        return head;
    }
};
