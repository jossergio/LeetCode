class Solution {
private:
        bool buscar (vector<int>& r, string& p, size_t i, unordered_set<int>& u) {
        if (i == p.size ()) return true;
        int sinal = 1; // Positivo; pressupõe
        if (p [i] == 'D') sinal = -1;
        for (int k = r [i] + sinal; k != 0 && k != 10; k += sinal) {
            if (u.count (k) == 0) {
                r [i + 1] = k;
                u.insert (k);
                if (buscar (r, p, i + 1, u)) return true; // Redispara
                u.erase (u.find (k));
            }
        }
        return false; // Segue para o próximo, no anterior
    }
public:
    string smallestNumber(string pattern) {
        const size_t t = pattern.size () + 1;
        vector<int> resposta (t);
        unordered_set<int> usados;
        for (int i = 1; i <= 9; i += 1) {
            resposta [0] = i;
            usados.insert (i);
            if (buscar (resposta, pattern, 0, usados)) break; // Achou
            usados.erase (usados.find (i));
        }
        string s (t, ' ');
        for (size_t i = 0; i < t; i += 1) s [i] = char ('0' + resposta [i]);
        return s;
    }
};
