class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int t = happiness.size ();
        sort (happiness.begin (), happiness.end ());
        long long resposta = 0;
        int decremento = 0;
        for (int i = t - 1; i >= t - k; i -= 1) { // O problema diz que k <= t
            cout << happiness [i] << " ... ";
            resposta += happiness [i] - (happiness [i] >= decremento ? decremento : happiness [i]); // Se tmp >= decremento, usa o decremento; senão, tira o que tiver
            cout << resposta << endl;
            decremento += 1;
        }
        return resposta;
    }
};

