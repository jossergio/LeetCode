class Solution {
private:
    int inc (int p, int s) {
        p += 1;
        if (p == s)
            return 0;
        // else
        return p;
    }
    int existe (vector<char> senado, char c, int p) {
        int referencia = p;
        while (p < senado.size () && senado [p] != c)
            p += 1;
        if (p == senado.size ()) { // Fará o complemento a partir do início
            p = 0;
            while (p < referencia && senado [p] != c)
                p += 1;
            if (p == referencia)
                return -1;
        }
        return p;
    }
public:
    string predictPartyVictory(string senate) {
        vector<char> senado = vector (senate.begin (), senate.end ());
        int pR = existe (senado, 'R', 0);
        int pD = existe (senado, 'D', 0);
        int pos = 0; // Inicia
        while (pR != -1 && pD != -1) {
            if (senado [pos] == 'R') {
                senado [pD] = 'B'; // Banir esse
                pD = existe (senado, 'D', pD + 1); // Aqui, checa se ficou algum
                pR = existe (senado, 'R', pR + 1); // Aqui, é para pegar o próximo, mesmo que seja o mesmo
            } else {
                if (senado [pos] == 'D') {
                    senado [pR] = 'B'; // Banir esse, também
                    pR = existe (senado, 'R', pR + 1); // Checa se ficou algum
                    pD = existe (senado, 'D', pD + 1); // Vai para o próximo, mesmo que seja o mesmo
                }
            }
            pos = inc (pos, senado.size ());
            while (senado [pos] == 'B')
                pos = inc (pos, senado.size ());
        }
        if (pR == -1) // Esse perdeu
            return "Dire";
        // else
        return "Radiant";
    }
};

