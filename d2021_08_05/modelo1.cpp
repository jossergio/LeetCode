class Solution {
private:
    vector<int> temp;
    vector<int> alex;
    vector<int> lee;
    int i, f; // Controle inicial e final do vetor geral
    
    int somas (vector<int>& v, int pi, int pf) {
        int r = 0;
        for (int a = pi; a <= pf; a++)
            r += v [a];
        return r;
    } // somas

    bool teste () {
        if ((somas (lee, 0, lee.size () - 1) + somas (temp, i, f)) < somas (alex, 0, alex.size () - 1))
            return true; // Alex ganha, independente de outras iterações
        return ganha (); // Próxima iteração
    } // teste
    
    bool ganha () {
        if (f > i) {
// Alex e Lee tiram do mesmo lado, esquerdo
            alex.push_back (temp [i++]);
            lee.push_back (temp [i++]);
            if (teste ()) // Alex já ganha
                return true; // É que se for falso, ainda não terminou
// Retorna Lee para tirar do lado direito            
            lee.pop_back ();
            i--;
            lee.push_back (temp [f--]);
            if (teste ())
                return true;
// Volta tudo e Alex e Lee começam tirando do lado direito
            f++;
            i--;
            alex.pop_back ();
            lee.pop_back ();
            alex.push_back (temp [f--]);
            lee.push_back (temp [f--]);
            if (teste ())
                return true;
// Retorna Lee para tirar do início
            f++;
            lee.pop_back ();
            lee.push_back (temp [i++]);
            if (teste ())
                return true;
            lee.pop_back ();
            alex.pop_back ();
            f++;
            i--;
        } // if f > i
        return false; // De uma forma ou de outra, Alex NÃO ganha
    }

public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size () > 2) {
            temp = piles;
            i = 0;
            f = temp.size () - 1;
            return (ganha () == 1);
        } // if piles.size > 2
        return true; // De uma forma ou de outra, ganha Alex
    } // 
};

