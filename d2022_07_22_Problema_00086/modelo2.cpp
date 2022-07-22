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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* menores = new ListNode (); // Será descartado depois
        ListNode* maiores = new ListNode (); // Idem
        ListNode* menoresSeq = menores;
        ListNode* maioresSeq = maiores;
        
        while (head) {
            if (head->val >= x) {
                maioresSeq->next = head;
                maioresSeq = maioresSeq->next;
            } else {
                menoresSeq->next = head;
                menoresSeq = menoresSeq->next;
            }
            head = head->next;
        }
        
        maioresSeq->next = nullptr; // Só para finalizar a lista
        menoresSeq->next = maiores->next;
        
        return menores->next;
        
    }
};

