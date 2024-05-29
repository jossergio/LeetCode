class Solution {
private:
    void somar (string& s) { // Soma 1 à representação numérica binária da string
        int vaiUm = 1; // É justamente a própria soma com 1
        for (int i = s.size () - 1; i >= 0; i--) {
            if (s [i] == '1' && vaiUm == 1) {
                s [i] = '0'; // E mantém vaiUm em 1
            } else {
                if (s [i] == '1' || vaiUm == 1) { // Um dos dois, aqui, será zero
                    s [i] = '1'; // Possa ser que mantenha
                    vaiUm = 0; // Possa ser que seja redundante
                    break; // Não precisa fazer mais nada a partir daqui; sai logo
                }
            }
        }
        if (vaiUm == 1) { // Sobrou algo
            s = '1' + s;
        }
    } // soma

    void dividir (string& s) { // Divide por dois
        s.pop_back (); // O mesmo que <<
    }
public:
    int numSteps(string s) {
        int contagem = 0;
        while (s.size () > 1) {
            if (s.back () == '1') {
                somar (s);
            } else {
                dividir (s);
            }
            contagem += 1;
        }
        return contagem;
    }
};

