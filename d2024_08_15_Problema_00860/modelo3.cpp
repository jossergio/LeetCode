class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cedulas_5 = 0;
        int cedulas_10 = 0;
        // De 20, não precis
        for (int& b: bills) {
            switch (b) {
                case 5: cedulas_5 += 1; break; // Não há troco
                case 10:
                    cedulas_10 += 1;
                    cedulas_5 -= 1;
                    break;
                case 20:
                    cedulas_10 -= 1;
                    cedulas_5 -= 1;
                    if (cedulas_10 < 0) { // Fará um troco fracionado
                        cedulas_10 += 1;
                        cedulas_5 -= 2;
                    }
                    break;
            } // switch
            if (cedulas_5 < 0 || cedulas_10 < 0) return false; // Nâo foi possível fazeer o troco
        }
        return true; // Passou por todos os testes
    }
};

