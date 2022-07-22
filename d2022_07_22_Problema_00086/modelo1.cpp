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
        
        if (!head)
            return nullptr; // Já retorna daqui; e não atrapalha o algoritmo
        
        vector<ListNode*> menores;
        vector<ListNode*> maiores;
        
        while (head) {
            
            if (head->val >= x)
                maiores.push_back (head);
            else
                menores.push_back (head);
            
            head = head->next;
        }
        
        menores.insert (menores.end (), maiores.begin (), maiores.end ());
        
        menores [menores.size () - 1]->next = nullptr; // Fecha a lista
        
        for (int i = 0; i < menores.size () - 1; i++) // Obervar que só vai até o penúltimo
            menores [i]->next = menores [i + 1];

        head = menores [0];
        
        return head; // Haverá, pelo menos, 1
    }
};

