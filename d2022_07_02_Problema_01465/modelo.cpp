class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        const long long modulo = 1000000000 + 7;
        
        // Acrescenta os limites
        horizontalCuts.push_back (h);
        verticalCuts.push_back (w);
        
        sort (horizontalCuts.begin (), horizontalCuts.end ());
        sort (verticalCuts.begin (), verticalCuts.end ());
        
        // Valores iniciais de referência
        long long base = horizontalCuts [0];
        long long altura = verticalCuts [0];
        
        // Procura os valores maiores
        for (int i = 1; i < horizontalCuts.size (); i++) {
            long long tmp = horizontalCuts [i] - horizontalCuts [i - 1];
            if (tmp > base)
                base = tmp;
        }
        
        for (int i = 1; i < verticalCuts.size (); i++) {
            long long tmp = verticalCuts [i] - verticalCuts [i - 1];
            if (tmp > altura)
                altura = tmp;
        }
        
        long long resposta = (base * altura) % modulo;
        
        return int (resposta);
    }
};

