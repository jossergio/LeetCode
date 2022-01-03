class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> totalConfiancas (n, 0); // Atenção! Os valores irão de 1 a n e não de 0 a n - 1
        vector<bool> confiancas (n, false);
        for (int a = 0; a < trust.size (); a++) {
            totalConfiancas [trust [a][1] - 1]++; // Indiferente de já ser ou não; Atenção para o -1
            confiancas [trust [a][0] - 1] = true;
        }
        int jaTem = false;
        int juiz = -1;
        for (int a = 0; a < confiancas.size (); a++)
            if (!confiancas [a]) {
                if (jaTem)
                    return -1; // Já há, pelo menos, um juiz. Sai logo.
                jaTem = true; // Encontrou ou primeiro
                juiz = a; // Provável. Atenção! É de 1 a n. Ajustar depois.
            }
        if (juiz != -1 && totalConfiancas [juiz] == n - 1)
            return juiz + 1; // Recompõe
        return -1; // Não achou
    }
};

