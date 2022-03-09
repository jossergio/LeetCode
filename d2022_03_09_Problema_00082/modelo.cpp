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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *base = head;
        ListNode *anterior = nullptr;
        
        while (base != nullptr) {
            
            ListNode *proximo = base->next;
            
            if (proximo != nullptr && proximo->val == base->val) {
                while (proximo != nullptr && proximo->val == base->val)
                    proximo = proximo->next;
                if (anterior != nullptr) {
                    anterior->next = proximo;
                } else
                    head = proximo;
            } else
                anterior = base;
            
            base = proximo;
            
        }
        
        return head;
    }
};

