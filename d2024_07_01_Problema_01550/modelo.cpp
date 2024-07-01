class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cont = 0;
        for (int a: arr) {
            if (a & 1 == 1)
                cont += 1;
            else
                cont = 0; // Reinicia a contagem
            if (cont == 3)
                return true;
        }
        return false; // Nãosachou
    }
};

