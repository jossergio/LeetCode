class Solution {
private:
    bool seguro (int i, vector<vector<int>>& g, vector<bool>& p, vector<bool>& m, vector<bool>& v) {
        if (v [i])
            return false; // Se já visitou, forma ciclo e não é seguro
        if (!p [i]) { // Ainda não processado
            v [i] = true; // Marca como visitado; não precisa desmarcar; por valor
            for (int n: g [i]) { // E vai em busca de ver se é seguro
                m [i] = m [i] && seguro (n, g, p, m, v); // Lembrar que, incialmente, é verdadeiro
            }
            v [i] = false; // E desmarca como visitado, aqui
            p [i] = true; // Marca que já processou
        } // if !p [i]
        return m [i];
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> resposta;
        const int t = graph.size (); // Será utilizado várias vezes
        vector<bool> processados (t, false);
        vector<bool> memo (t, true);
        vector<bool> visitados (t, false);
        for (int i = 0; i < t; i += 1)
            if (seguro (i, graph, processados, memo, visitados))
                resposta.push_back (i);
        return resposta; // Já vem ordenado, por conta do laço crescente
    }
};

