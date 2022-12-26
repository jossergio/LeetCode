class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> respostas (queries.size (), 0);
        vector<int> ordenado (nums); // Para evitar ficar ordenado a cada iteração
        sort (ordenado.begin (), ordenado.end ());
        int fixaSoma = accumulate (ordenado.begin (), ordenado.end (), 0); // Idem para a soma
        for (int q = 0; q < queries.size (); q++) {
            vector<int> tmp (ordenado);
            int soma = fixaSoma;
            while (soma > queries [q] && tmp.size () > 0) {
                soma -= tmp.back ();
                tmp.pop_back ();
            }
            respostas [q] = tmp.size ();
        }
        return respostas;
    }
};

