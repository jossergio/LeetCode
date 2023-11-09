class Solution {
public:
    static const int modulo = 1000000007;
    int pegaValor (int i, vector<int>& m) {
        if (i > m.size ()) {
            if (i == 1) {
                m.push_back (1);
            } else {
                m.push_back ((i + pegaValor (i - 1, m)) % modulo);
            }
        }
        return m [i - 1]; // 0-begin
    }
    int countHomogenous(string s) {
        vector<int> memo;
        int i = 0;
        const int t = s.size ();
        int resposta = 0;
        while (i < t) {
            int tmp = 0;
            auto c = s [i];
            while (i < t && s [i] == c) {
                tmp += 1;
                i += 1;
            }
            resposta = (resposta + pegaValor (tmp, memo)) % modulo;
        }
        return resposta;
    }
};

