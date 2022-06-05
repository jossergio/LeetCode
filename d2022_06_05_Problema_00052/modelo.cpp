class Solution {
private:
    vector<vector<string>> solucoes;
    vector<string> solucao;
    
    string linha (int i, int n) {
        return string (i, '.') + "Q" + string (n - i - 1, '.');
    }
    
    bool pode (int i, int n) {
        if (solucao.empty ()) // Se tá vazio, sempre poderá
            return true;
        
        int deslocamento = 1; // Será utilizado em ambos os lados
        int tmp; // Será utilizado como temporário no cálculo do deslocamento
        
        // Basta ter em uma linha acima na mesma coluna, não pode
        // Basta ter em uma linha acima e na mesma diagonal, à direita ou à esquerda
        // calculado com deslocamento, não pode
        for (vector<string>::reverse_iterator linha = solucao.rbegin (); linha != solucao.rend (); linha++) { // Notar que é reverso, para acompanhar deslocamento
            
            if ((*linha) [i] == 'Q')
                return false;
            
            if ((tmp = (i - deslocamento)) >= 0) { // Tem que testar
                if ((*linha) [tmp] == 'Q')
                    return false;
            }
            
            if ((tmp = (i + deslocamento)) < n) { // Tem que testar
                if ((*linha) [tmp] == 'Q')
                    return false;
            }
            
            deslocamento++; // Para a próxima linha, o deslocamento e incrementado
        }
        
        // Se fez todos os testes e passou, pode
        return true;
    }
    
    void solucionar (int nivel, int n) {
        if (nivel == n) { // Se chegou aqui, é uma solução
            solucoes.push_back (solucao);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (pode (i, n)) {
                solucao.push_back (linha (i, n));
                solucionar (nivel + 1, n);
                solucao.pop_back ();
            }
        }
    }

public:
    int totalNQueens(int n) {
        solucoes.clear ();
        
        solucionar (0, n);
        
        return solucoes.size ();

    }
};

