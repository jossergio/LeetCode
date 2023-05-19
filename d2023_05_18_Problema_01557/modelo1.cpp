class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> chega = vector (n, false);
        for (auto v: edges)
            chega [v [1]] = true;
        vector<int> resposta;
        for (int i = 0; i < n; i += 1)
            if (!chega [i])
                resposta.push_back (i);
        return resposta;
    }
};

