class Solution {
private:
    void buscar (vector<int>& nums, int i, unordered_map<int, int>& t, int acum) {
        if (i < nums.size ()) {
            int tmp = acum | nums [i];
            t [tmp] += 1;
            for (int j = i + 1; j < nums.size (); j += 1) buscar (nums, j, t, tmp);
        }
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> tabela;
        for (int i = 0; i < nums.size (); i += 1) buscar (nums, i, tabela, 0); // 0 é elemento neutro
        int resposta = 0; // Padrão
        int ver = 0; // Comparativo inicial; elemento neutro
        for (auto [v, c]: tabela) {
            if (v > ver) {
                resposta = c;
                ver = v;
            }
        }
        return resposta;
    }
};
