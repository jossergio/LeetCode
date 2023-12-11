class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int contagem = 0;
        int anterior = arr [0]; // Há, pelo menos, um
        const float t = arr.size (); // Pois o calculo será fracionário/decimal
        for (int i: arr) {
            if (i == anterior) {
                contagem += 1;
                if (contagem / t > 0.25)
                    return i;
            } else {
                contagem = 1;
                anterior = i;
            }
        }
        return arr [t - 1]; // Nem chega aqui; só para constar
    }
};

