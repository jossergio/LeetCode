class Solution {
private:
    void gerar (int n, int k, int acumulado, int algarismoAtual, vector<int>& acumulados) {
        
        if (algarismoAtual < 0 || algarismoAtual > 9)
            return; // Não há o que fazer a patir daqui
        
        if (n == 1) { // Coindice com a unidade
            acumulados.push_back (acumulado + algarismoAtual);
            return;
        }
        
        gerar (n - 1, k, acumulado + algarismoAtual * pow (10, n - 1), algarismoAtual - k, acumulados);
        if (k != 0) // LeetCode; se k == 0, gera em duplicidade; basta um
            gerar (n - 1, k, acumulado + algarismoAtual * pow (10, n - 1), algarismoAtual + k, acumulados);
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> resposta;
        
        for (int primeiro = 1; primeiro <= 9; primeiro++) {
            gerar (n - 1, k, primeiro * pow (10, n - 1), primeiro - k, resposta);
            if (k != 0) // Ver comentário na função gerar
                gerar (n - 1, k, primeiro * pow (10, n - 1), primeiro + k, resposta);
        }
        
        return resposta;
    }
};

