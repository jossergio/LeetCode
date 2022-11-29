class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> perdas;
        for (auto item: matches) { // Cada item possui dois itens; 0 é ganhador, 1 é perdedor
            perdas [item [0]] += 0; // Para criar ou manter; item 0 é vitória
            perdas [item [1]] += 1;
        }
        vector<vector<int>> resposta (2); // Tamanho 2
        for (auto m: perdas) {
            if (m.second == 0)
                resposta [0].push_back (m.first);
            else
                if (m.second == 1)
                    resposta [1].push_back (m.first);
            // Os demais não entram na resposta
        }
        sort (resposta [0].begin (), resposta [0].end ());
        sort (resposta [1].begin (), resposta [1].end ());
        return resposta;
    }
};

