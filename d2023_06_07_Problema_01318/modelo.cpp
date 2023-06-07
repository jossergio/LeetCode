class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cont = 0;
        while (! (a == 0 && b == 0 && c == 0)) {
            int ta = a & 1; // Pega o último bit
            int tb = b & 1; // Idem
            int tc = c & 1; // Idem
            if ((ta | tb) != tc) { // Os bits são diferentes
                if (tc == 1) { // Ambos são zero
                    cont += 1; // Basta tornar um deles um
                } else { // tc == 0
                    // Pelo menos um dos dois é um
                    // E cada um tem que ser checado e convertido
                    if (ta == 1)
                        cont += 1;
                    if (tb == 1)
                        cont += 1;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cont;
    }
};

