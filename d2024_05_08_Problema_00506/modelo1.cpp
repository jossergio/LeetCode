class Solution {
private:
    int c = 1; // Tem que declarar aqui, para poder ser incrementada na closure, abaixo
    function<string ()> pegarProximo () {
        return [this] () -> string { // Usar this para poder capturar a variável c
            string resposta;
            switch (c) {
                case 1: resposta = "Gold Medal"; break;
                case 2: resposta = "Silver Medal"; break;
                case 3: resposta = "Bronze Medal"; break;
                default: resposta = to_string (c);
            }
            c += 1;
            return resposta;
        }; // closure
    } // pegarProximo
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int t = score.size ();
        priority_queue<pair<int, int>> organizador;
        for (int i = 0; i < t; i += 1)
            organizador.push ({score [i], i});
        pair<int, int> tmp; // Para ser utilizado no laço, abaixo
        vector<string> resposta (t);
        auto proximo = pegarProximo ();
        while (!organizador.empty ()) {
            tmp = organizador.top ();
            organizador.pop ();
            resposta [tmp.second] = proximo ();
        }
        return resposta;
    }
};

