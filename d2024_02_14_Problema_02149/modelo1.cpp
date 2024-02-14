class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positivos;
        queue<int> negativos;
        const int t = nums.size ();
        vector<int> resposta (t, 0);
        auto nPonteiro = nums.begin ();
        // Já define o primeiro, pois o laço se baseia, somente, nas filas
        if (*nPonteiro < 0)
            negativos.push (*nPonteiro);
        else // Só pode ser positivo
            positivos.push (*nPonteiro);
        nPonteiro++;
        int ponteiro = 0; // Posição do próximo elemento; melhor que push_back; resposta já tem tamanho
        while (!positivos.empty () || !negativos.empty ()) { // Os demais ponteiros são controlados internamente
        // A condição acima é base
            if ((ponteiro % 2) == 0 && !positivos.empty ()) {
                resposta [ponteiro++] = positivos.front ();
                positivos.pop ();
            }
            // Não precisa de else, pois é sequencial
            if ((ponteiro % 2) == 1 && !negativos.empty ()) {
                resposta [ponteiro++] = negativos.front ();
                negativos.pop ();
            }
            if (nPonteiro != nums.end ()) {
                if (*nPonteiro < 0)
                    negativos.push (*nPonteiro);
                else // Só pode ser positivo
                    positivos.push (*nPonteiro);
                nPonteiro++;
            }
        }
        // O algoritmo permite uma passagem só; caso contrário, teríamos que encher, primeiro e
        // num segundo momento, esvaziar as filas
        return resposta;
    }
};

