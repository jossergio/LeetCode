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
    ListNode* reverseList(ListNode* head) {
        
        queue<ListNode*> pilha;
        
        while (head != nullptr) {
            pilha.push (head);
            head = head->next;
        }
        // head termina nullptr
        
        while (!pilha.empty ()) {
            ListNode* tmp = pilha.front ();
            pilha.pop ();
            tmp->next = head;
            head = tmp;
        }
        
        return head;
    }
};

