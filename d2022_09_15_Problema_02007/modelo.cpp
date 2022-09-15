class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int> resposta;
        
        if (((changed.size () % 2) != 0) || changed.size () == 0) // Tem que ter tamanho par, no mínimo dois
            return resposta;
        
        sort (changed.begin (), changed.end ());
        
        queue<int> fila; // Utiliza como forma de fazer buscas por acumulação
        
        fila.push (changed [0]);
        
        auto i = changed.begin () + 1;
        
        while (i != changed.end ()) {
            
            int atual = fila.front ();
            fila.pop ();
            
            if (*i > atual * 2) { // Não há condições de ter elementos nessa faixa
                resposta.clear ();
                return resposta;
            }
            
            while ((i != changed.end ()) && (*i <= (2 * atual))) {
                if (atual * 2 == *i) {
                    resposta.push_back (atual);
                    i++;
                    break;
                } else {
                    fila.push (*i);
                    i++;
                }
            }
            
            if ((fila.empty ()) && (i != changed.end ())) {
                fila.push (*i);
                i++;
            }
            
        }
        
        if (fila.size () == 0)
            return resposta;
        // else
        resposta.clear ();
        return resposta;
    }
};

