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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*> lista;
        ListNode* no = head;
        
        // Pela definição do problema, haverá ao menos um item na lista
        while (no != nullptr) {
            lista.push_back (no);
            no = no->next;
        }
        
        // Pela definição do problema, n não está fora dos limites do tamanho da lista
        int item = lista.size () - n; // Já aproveita a conndição do 0-begin
        
        if (item == 0)
            head = head->next;
        else
            lista [item - 1]->next = lista [item]->next;
        
        return head;
    }
};

