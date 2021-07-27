class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int soma = nums [0] + nums [1] + nums [2]; // Assume que esse é o resultado
        int diferencaAtual = abs (target - soma);
        if (diferencaAtual == 0)
            return target; // É o valor
        int diferencaAnt = diferencaAtual;
        int resultado = soma;
        int a, b, c;
        int tamanho = nums.size (); // Irá utilizar várias vezes
        for (a = 0; a < tamanho; a++)
            for (b = a + 1; b < tamanho; b++)
                for (c = b + 1; c < tamanho; c++)
                    if ((diferencaAtual = abs (target - (soma = nums [a] + nums [b] + nums [c]))) <   diferencaAnt)
                        if (diferencaAtual == 0)
                            return target;
                        else {
                            diferencaAnt = diferencaAtual;
                            resultado = soma;
                        } // if else diferencaAtual == 0
        return resultado;
    }
};

