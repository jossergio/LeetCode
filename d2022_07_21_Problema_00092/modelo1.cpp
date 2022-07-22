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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        vector<ListNode*> lista;
        
        while (head) {
            lista.push_back (head);
            head = head->next;
        }
        
        while (left < right) {
            ListNode* tmp = lista [left - 1]; // 1-begin
            lista [left - 1] = lista [right - 1];
            lista [right - 1] = tmp;
            left++;
            right--;
        }
        
        lista [lista.size () - 1]->next = nullptr; // Fecha a lista
        
        for (int i = 0; i < lista.size () - 1; i++) // Só vai até o penúltimo
            lista [i]->next = lista [i + 1];
        
        return lista [0];
        
    }
};

