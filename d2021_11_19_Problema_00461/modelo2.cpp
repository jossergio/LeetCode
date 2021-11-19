class Solution {
public:
    int hammingDistance(int x, int y) {
		int diferenca = x ^ y;
        int distancia = 0;
        while (diferenca != 0) {
        	if ((diferenca & 1) == 1)
            	distancia++;
            diferenca >>= 1;
        } // while diferenca != 0
        return distancia;
    }
};

