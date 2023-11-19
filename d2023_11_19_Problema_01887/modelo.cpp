class ordem {
    public:
    ordem () {
        
    }
    bool operator () (const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        // else
        return a.first < b.first;
    }
};

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, ordem> minha_fila;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int resposta = 0;
        minha_fila fila;
        for (int i = 0; i < nums.size (); i += 1)
            fila.push (make_pair (nums [i], i));
        int anterior = 0;
        while (true) {
            pair<int, int> tmp = fila.top ();
            int contar = anterior; // Já pega o acumulado
            while (!fila.empty () && fila.top ().first == tmp.first) {
                contar += 1;
                fila.pop ();
            }
            if (fila.empty ()) // Não há mais o que fazer
                break;
            resposta += contar;
            anterior = contar;
        }
        return resposta;
    }
};

