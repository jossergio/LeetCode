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
    bool isPalindrome(ListNode* head) {
        
        stack<ListNode*> pilha;
        ListNode* item = head;
        
        while (item) {
            pilha.push (item);
            item = item->next;
        }
        
        while (head) {
            if (head->val != pilha.top ()->val)
                return false;
            head = head->next;
            pilha.pop ();
        }
        
        return true;
    }
};

