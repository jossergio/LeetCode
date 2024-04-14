class Solution {
private:
    vector<int> pilha;
    int posicaoPilha = 0;
    void iniciarPilha (int t) { pilha.resize (t); } // Pelo máximo
// = = =
    int incluirPilha (int v) { // Retorna possível valor acumulado
        int retorno = 0;
        if (posicaoPilha == 0) {
            pilha [posicaoPilha++] = v;
        } else {
            if (pilha [posicaoPilha - 1] >= v) {
                pilha [posicaoPilha++] = v;
            } else { // if pilha posicaoPilha - 1 >= v
                int temp = 0;
                while (temp < posicaoPilha && pilha [temp] > v)
                    temp++;
                for (int temp2 = temp + 1; temp2 < posicaoPilha; temp2++) {
                    retorno += pilha [temp] - pilha [temp2];
                    pilha [temp2] = pilha [temp];
                } // for temp2
                if (temp == 0) {
                    posicaoPilha = 0; // Isso
                } else { // if temp == 0
                    for (int temp2 = temp; temp2 < posicaoPilha; temp2++) {
                        retorno += v - pilha [temp2];
                        pilha [temp2] = v;
                    } // for temp2 ... (2)
                } // if temp == 0 ... else
                pilha [posicaoPilha++] = v;
            } // if pilha [osicaoPilha] >= v ... else
        } // if posicaoPilha == 0 ... else
        return retorno;
    } // incluirPilha 
// = = =
public:
    int trap(vector<int>& height) {
        int tamanho = height.size ();
        int acumulador = 0;
        iniciarPilha (tamanho);
        for (int a = 0; a < tamanho; a++)
            acumulador += incluirPilha (height [a]);
        return acumulador;
    }
};

