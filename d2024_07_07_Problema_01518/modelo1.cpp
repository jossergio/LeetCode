class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int resposta = 0;
        int vazias = 0;
        while (numBottles > 0) {
            resposta += numBottles;
            vazias += numBottles;
            numBottles = vazias / numExchange;
            vazias %= numExchange;
        }
        return resposta;
    }
};

