class Solution {
private:
    void buscarCaminho (vector<int>& caminho, vector<bool>& visitados, vector<int>& edges, int nivel, int no) {
        if (visitados [no])
            return; // Nem tenta mais
        visitados [no] = true;
        caminho [no] = nivel++;
        if (edges [no] != -1)
            buscarCaminho (caminho, visitados, edges, nivel, edges [no]);
        visitados [no] = false; // Restaura
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> caminho1 = vector (edges.size (), -1);
        vector<int> caminho2 = vector (edges.size (), -1);
        vector<bool> visitados = vector (edges.size (), false);
        buscarCaminho (caminho1, visitados, edges, 0, node1);
        buscarCaminho (caminho2, visitados, edges, 0, node2);
        int indiceMenor = -1; // Por padrão, se não houver nenhum
        int distanciaMenor; // Maior até o momento; calculado em contingência
        int jaCalculado = false; // Forçará calcular o primeiro
        for (int i = 0; i < edges.size (); i += 1)
            if (caminho1 [i] != -1 && caminho2 [i] != -1)
                if (distanciaMenor > max (caminho1 [i], caminho2 [i]) || !jaCalculado) {
                    distanciaMenor = max (caminho1 [i], caminho2 [i]);
                    indiceMenor = i; // Mantém o menor índice, em caso de duplicidade
                    jaCalculado = true;
                    }
        return indiceMenor;
    }
};

