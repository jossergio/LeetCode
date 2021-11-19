class Solution {
public:
    int hammingDistance(int x, int y) {
		int diferenca = x ^ y;
        int distancia = -1;
        while (diferenca != 0) {
            if (diferenca & 1) {
                if (distancia == -1) {
                    distancia = 1;
                };
            } else { // if diferenca & 1
            	if (distancia > 0)
                	distancia++;
            } // else if diferenca & 1
            diferenca >>= 1;
        } // while diferenca != 0
        return distancia;
    }
};

