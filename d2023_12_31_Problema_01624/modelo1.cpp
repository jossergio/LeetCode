class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> posicoes (26, -1); // Podia ser map's, mas precisava inicializar com -1
        const int t = s.size ();
        int resposta = -1; // Esse é o padrão, caso não encontre
        for (int i = 0; i < t; i += 1) {
            int p = s [i] - 'a'; // Para simplificar o visual do código
            if (posicoes [p] != -1)
                resposta = max (resposta, i - posicoes [p] - 1); // Os extremos não contam
            else // Só atualiza no primeiro
                posicoes [p] = i;
        }
        return resposta;
    }
};

