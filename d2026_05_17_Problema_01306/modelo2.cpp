class Solution {
private:
    bool buscar (vector<int>& a, int i, vector<bool>& p) {
        // Condições de saída
        if (a [i] == 0) { return true; }
        if (p [i]) { return false; }
        p [i] = true;
        bool resposta = // Por conta do control de passagens, precisa armazenar em variável
            (i - a [i] >= 0 && buscar (a, i - a [i], p)) ||
            (i + a [i] < a.size () && buscar (a, i + a [i], p));
        p [i] = false;
        return resposta;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> passou (arr.size (), false);
        return buscar (arr, start, passou);
    }
};
