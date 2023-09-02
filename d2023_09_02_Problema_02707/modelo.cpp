class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size (); // Usaremos muitas vezes
        unordered_set<string> dicionarioSet (dictionary.begin (), dictionary.end ()); // Para otimizar buscas
        unordered_map<int, int> memo; // Para armazenar as etaps e evitar que a recursividade seja utilizada quando já houve cálculo
        
        function<int (int)> dp = [&] (int inicio) { // Todas as variáveis da função principal serão utilizadas
            if (inicio == n)
                return 0; // Não há mais o que fazer; condição de saída da recursividade
            if (memo.count (inicio)) // Checa se já houve cálculo para essa base
                return memo [inicio];
            int resposta = dp (inicio + 1) + 1; // Segue para o final, para já montar o valor base a partir daqui; é n, na pior das hipóteses
            for (int fim = inicio; fim < n; fim += 1) {
                string atual = s.substr (inicio, fim - inicio + 1);
                if (dicionarioSet.count (atual))
                    resposta = min (resposta, dp (fim + 1));
            }
            return memo [inicio] = resposta; // Atualiza o memo e retorna seu valor atual no índice inicio
        }; // function dp
        
        return dp (0);
    }
};

