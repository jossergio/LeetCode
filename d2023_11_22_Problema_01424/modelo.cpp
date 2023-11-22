class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> diagonais;
        for (int i = nums.size () - 1; i >= 0; i -= 1)
            for (int j = 0; j < nums [i].size (); j += 1)
                diagonais [i + j].push_back (nums [i][j]);
        int diagonal = 0;
        vector<int> resposta;
        while (true) {
            if (diagonais.count (diagonal) > 0)
                for (int d: diagonais [diagonal])
                    resposta.push_back (d);
            else
                break; // Não há mais diagonais
            diagonal += 1;
        }
        return resposta;
    }
};

