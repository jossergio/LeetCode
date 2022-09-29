class Solution {
private:
    int buscar (vector<int>& vetor, int i, int j, int x) {
        if (j <= i) {
            if (j == i && vetor [i] != x)  // Uma simplificação, caso não haja o elemento
                return i; // Tanto faz aqui ou no teste
            // else
            if (j < 0)
                return i;
            else // i deve ser maior que o tamanho do vetor
                return j;
        }
        // else
        int meio = (i + j) / 2;
        if (vetor [meio] == x)
            return meio;
        // else
        if (vetor [meio] > x)
            return buscar (vetor, i, meio - 1, x);
        // else
        return buscar (vetor, meio + 1, j, x);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int indice = buscar (arr, 0, arr.size () - 1, x);
        vector<int> resposta;
        int iEsquerda = indice - 1;
        int iDireita = indice + 1;
        if (arr [indice] == x)
            resposta.push_back (arr [indice]); // O primeiro é o próprio; ordeno depois
        else {
            if (iEsquerda >= 0 && iDireita < arr.size ()) {
                if ((x - arr [iEsquerda]) <= (arr [iDireita] - x))
                    iDireita -= 1;
                else
                    iEsquerda += 1;
            } else {
                iEsquerda = max (0, iEsquerda);
                iDireita = min (iDireita, int (arr.size () - 1));
            }
        }
        while (resposta.size () < k) {
            if (iEsquerda >= 0 && iDireita < arr.size ()) {
                int esquerda = x - arr [iEsquerda]; // x é maior
                int direita = arr [iDireita] - x; // x é menor
                if (direita >= esquerda) {
                    resposta.push_back (arr [iEsquerda]);
                    iEsquerda -= 1;
                } else { // direta > esquerda
                    resposta.push_back (arr [iDireita]);
                    iDireita += 1;
                }
            } else {
                if (iEsquerda < 0) {
                    resposta.push_back (arr [iDireita]);
                    iDireita += 1;
                } else {
                    resposta.push_back (arr [iEsquerda]);
                    iEsquerda -= 1;
                }
            }
        }
        sort (resposta.begin (), resposta.end ());
        return resposta;
    }
};

