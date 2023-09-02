class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size (); // Usaremos muitas vezes
        
        function<int (int)> buscar = [&] (int inicio) { // Usará tudo da principal
            if (inicio == n) // Não há mais sobras por aqui
                return 0;
            int minimo = n - inicio; // Pressupõe que todo o resto sobra; também é condição de não ter encontrado
            for (string palavra: dictionary)
                if (n - inicio >= palavra.size ()) {
                    if (s.substr (inicio, palavra.size ()) == palavra)
                        minimo = min (minimo, buscar (inicio + palavra.size ()));
                    if (minimo == 0) // Condição de saída, para otimizar
                        return 0;
                }
            return (minimo == n - inicio)? 1 + buscar (inicio + 1): minimo;
        }; // function buscar
        
        return buscar (0);
    }
};

