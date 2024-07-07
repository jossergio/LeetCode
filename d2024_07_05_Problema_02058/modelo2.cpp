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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> lista;
        while (head != nullptr) {
            lista.push_back (head->val);
            head = head->next;
        }
        int t = lista.size ();
        vector<int> pontos; // Conterá os índices dos pontos críticos
        for (int i = 1; i < t - 1; i += 1) { // Começa do segundo e termina no penúltimo
            if ((lista [i] < lista [i - 1] && lista [i] < lista [i + 1]) || 
                (lista [i] > lista [i - 1] && lista [i] > lista [i + 1])) { // É um ponto crítico
                pontos.push_back (i);
            }
        }
        t = pontos.size ();
        int menor = t > 1 ? pontos [t - 1] - pontos [0] : -1; // Pressupõe
        int maior = t > 1 ? pontos [t - 1] - pontos [0] : -1;
        for (int i = 1; i < t; i += 1) { // A partir do segundo
            menor = min (menor, pontos [i] - pontos [i - 1]);
        }
        return {menor, maior};
    }
};

