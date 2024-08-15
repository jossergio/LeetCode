class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> cedulas; // Os tipos de notas
        cedulas [5] = 0;
        cedulas [10] = 0;
        cedulas [20] = 0;
        for (int& b: bills) {
            cedulas [b] += 1; // Armazena a cédula no correspondente
            b -= 5; // Faz o pagamento
            while (b >= 20 && cedulas [20] > 0) {
                b -= 20;
                cedulas [20] -= 1;                
            }
            while (b >= 10 && cedulas [10] > 0) {
                b -= 10;
                cedulas [10] -= 1;
            }
            while (b >= 5 && cedulas [5] > 0) {
                b -= 5;
                cedulas [5] -= 1;
            }
            if (b > 0) return false; // Não foi possível fazer o troco
        }
        return true; // Passou por todos os testes
    }
};

