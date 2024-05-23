class Solution {
private:
    bool ehPalindoromo (string& s) {
        int i = 0, j = s.size () - 1;
        while (i <= j) {
            if (s [i] != s [j])
                return false;
            i += 1;
            j -= 1;
        }
        return true; // Passou nos testes
    }
    void preparar (string& s, int p, vector<vector<string>>& resp, vector<string> acum) {
        if (p == s.size ()) { // Só chega aqui se preencheu
            resp.emplace_back (vector<string> (acum.begin (), acum.end ()));
            return; // Nao precisa fazer andamento
        }
        // else
        string tmp;
        for (int i = p; i < s.size (); i += 1) {
            tmp.push_back (s [i]);
            if (ehPalindoromo (tmp)) {
                acum.push_back (tmp);
                preparar (s, i + 1, resp, acum);
                acum.pop_back ();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> resposta;
        vector<string> acumulado;
        preparar (s, 0, resposta, acumulado);
        return resposta;
    }
};

