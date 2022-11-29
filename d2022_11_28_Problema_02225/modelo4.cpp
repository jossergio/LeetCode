class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> perdas;
        for (auto item: matches) { // Cada item possui dois itens; 0 é ganhador, 1 é perdedor
            perdas [item [0]] += 0; // Para criar ou manter; item 0 é vitória
            perdas [item [1]] += 1;
        }
        // map guarda as chaves ordenadamente
        vector<vector<int>> resposta (2); // Tamanho 2
        for (auto m: perdas) {
            if (m.second == 0)
                resposta [0].push_back (m.first);
            else
                if (m.second == 1)
                    resposta [1].push_back (m.first);
            // Os demais não entram na resposta
        }
        return resposta;
    }
};

