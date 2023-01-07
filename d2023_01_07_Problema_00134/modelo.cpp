class Solution {
private:
    int incremento (int i, int t) {
        i +=1;
        return (i == t ? 0 : i);
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tamanho = gas.size (); // cost também tem o mesmo tamanho
        vector<int> acumulados (tamanho);
        for (int i = 0; i < tamanho; i += 1)
            acumulados [i] = gas [i] - cost [i];
        for (int i = 0; i < tamanho; i += 1) {
            if (gas [i] == 0 || acumulados [i] < 0) // Não tem, nem, como sair do lugar
                continue; // Agiliza
            int acumulado = acumulados [i];
            int indice = incremento (i, tamanho); // Começa no próximo
            while (indice != i && acumulado >= 0) {
                acumulado += acumulados [indice];
                if (acumulado >= 0) // Só para garantir que seguirá e incremenmtará
                    indice = incremento (indice, tamanho);
                // else: irá sair de qualquer jeito; não precisa de break
            }
            if (indice == i)
                return i; // Achou
        }
        return -1; // Não achou
    }
};

