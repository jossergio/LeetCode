class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mapa;
        for (int& n: nums)
            mapa [n] += 1;
        int resposta = 0;
        for (auto& [i, v]: mapa) {
            if (v == 1)
                return -1; // Impossível fazer operações
            if (v % 3 == 0)
                resposta += v / 3;
            else {
                if (v % 3 == 1) // Mesmo que seja o 4
                    resposta += (v - 4) / 3 + 2; // Os dois pares que sobram
                else // Só pode ser resto 2
                    resposta += (v - 2) / 3 + 1; // O par que sobra
            }
        }
        return resposta;
    }
};

