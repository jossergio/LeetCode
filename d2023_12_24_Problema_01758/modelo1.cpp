class Solution {
public:
    int minOperations(string s) {
        const int t = s.size ();
        int resposta1 = 0;
        string tmp (s);
        for (int i = 1; i < t; i += 1) { // Começa do segundo
            if (tmp [i - 1] == tmp [i]) {
                resposta1 += 1;
                if (tmp [i] == '1')
                    tmp [i] = '0';
                else // Só pode ser '1'
                    tmp [i] = '1';
            }
        }
        tmp = s;
        // O próximo código é só para iniciar com uma inversão na primeira casa
        if (tmp [0] == '1')
            tmp [0] = '0';
        else
            tmp [0] = '1';
        int resposta2 = 1; // Já fez a primeira inversão
        for (int i = 1; i < t; i += 1) { // Começa do segundo
            if (tmp [i - 1] == tmp [i]) {
                resposta2 += 1;
                if (tmp [i] == '1')
                    tmp [i] = '0';
                else // Só pode ser '1'
                    tmp [i] = '1';
            }
        }
        return min (resposta1, resposta2);
    }
};

