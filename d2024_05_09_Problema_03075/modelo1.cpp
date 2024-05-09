class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int t = happiness.size ();
        priority_queue<int> organizado;
        for (int v: happiness)
            organizado.push (v);
        long long resposta = 0;
        int decremento = 0;
        while (!organizado.empty () && decremento < k) {
            int tmp = organizado.top ();
            organizado.pop ();
            resposta += tmp - (tmp >= decremento ? decremento : tmp); // Se tmp >= decremento, usa o decremento; senão, tira o que tiver
            decremento += 1;
        }
        return resposta;
    }
};

