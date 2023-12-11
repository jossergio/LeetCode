class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int contagem = 0;
        int anterior = arr [0]; // Há, pelo menos, um
        const int indice = arr.size () / 4; // Equivakente a 1/4 de arr, ou 0.25%
        for (int i: arr) {
            if (i == anterior) {
                contagem += 1;
                if (contagem > indice)
                    return i;
            } else {
                contagem = 1;
                anterior = i;
            }
        }
        return arr [0]; // Nem chega aqui; só para constar
    }
};

