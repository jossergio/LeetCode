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
    void ajudante (ListNode* &no, int& nivel) {
        if (no) {
            int nivelLocal = nivel;
            nivel += 1;
            ajudante (no->next, nivel);
            if (nivelLocal == (nivel / 2)) {
                no = no->next;
            }
        }
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int nivelAjudante = 0;
        ajudante (head, nivelAjudante);
        return head;
    }
};

