class Solution {
private:
    vector<bool> passou;
    
    bool podeChegar (vector<int>& vetor, int posicao) {
        if (passou [posicao])
            return false; // Senão, pode entrar em laço
        if (vetor [posicao] == 0)
            return true; // Chegou
        passou [posicao] = true; // posicao já vem testado e está dentro dos limites de vetor
        if (posicao + vetor [posicao] < vetor.size ())
            if (podeChegar (vetor, posicao + vetor [posicao]))
                return true;
        if (posicao - vetor [posicao] >= 0)
            if (podeChegar (vetor, posicao - vetor [posicao]))
                return true;
        passou [posicao] = false; // Retorna ao estado anterior
        return false; // Padrão. Se chegou até aqui, não encontrou
    } // bool podeChegar
    
public:
    bool canReach(vector<int>& arr, int start) {
        passou.assign (arr.size (), false); // Redimensiona e atribui padrão
        if (arr [start] == 0)
            return true; // Nem começou e já chegou
        passou [start] = true; // Já informa que passou pelo inicial
        if (start + arr [start] < arr.size ())
            if (podeChegar (arr, start + arr [start]))
                return true; // Não pode pegar o valor de retorno.
                // Se falso, tem que testar o próximo passo.
        if (start - arr [start] >= 0)
            if (podeChegar (arr, start - arr [start]))
                return true;
        return false; // Padrão. Se chegou até aqui, não encontrou
    }
};

