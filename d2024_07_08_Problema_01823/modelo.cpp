class Solution {
public:
    int findTheWinner(int n, int k) {
        ListNode* cabeca = new ListNode (1); // 1-begin
        ListNode* proximo = cabeca;
        for (int i = 2; i <= n; i += 1) { // O primeiro já foi colocado
            proximo->next = new ListNode (i);
            proximo = proximo->next;
        }
        proximo->next = cabeca;
        ListNode* anterior = proximo; // Só para mudar de nome
        while (cabeca->next != cabeca) {
            for (int j = 1; j < k; j += 1)  { // O atual conta
                anterior = cabeca;
                cabeca = cabeca->next;
            }
            anterior->next = cabeca->next;
            cabeca = cabeca->next;
        }
        return cabeca->val;
    }
};

