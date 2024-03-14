class Solution {
public:
    int pivotInteger(int n) {
        int soma = 0;
        for (int i = 1; i <= n; i += 1)
            soma += i;
        int soma2 = 0;
        for (int pivo = 1; pivo <= n; pivo += 1) {
            soma2 += pivo;
            if (soma2 > soma)
                break; // Não há como haver reposta depois que ultrapassa
            if (soma == soma2)
                return pivo;
            soma -= pivo; // Tem que ser aqui, pois pivo entra nas duas somas
        }
        return -1;
    }
};

