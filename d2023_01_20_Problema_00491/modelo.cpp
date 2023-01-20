class Solution {
private:
    void procurar (vector<int>& nums, set<vector<int>>& resultado, vector<int>& atual, int indice) {
        if (!(indice < nums.size ()))
            return;
        if (nums [indice] >= atual.back ()) {
            atual.push_back (nums [indice]);
            resultado.insert (atual); // Com certeza, há, pelo menos, dois
            procurar (nums, resultado, atual, indice + 1);
            atual.pop_back ();
        }
        procurar (nums, resultado, atual, indice + 1); // Saltou o atual, que era menor, mas poderá incluir os próximos
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resultado;
        vector<int> atual;
        for (int i = 0; i < nums.size (); i += 1) {
            atual.push_back (nums [i]);
            procurar (nums, resultado, atual, i + 1);
            atual.pop_back ();
        }
        return vector (resultado.begin (), resultado.end ());
    }
};

