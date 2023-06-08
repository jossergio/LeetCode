class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int contagem = 0;
        const int limite = grid [0].size () - 1;
        for (auto interno: grid) {
            auto i = interno.rbegin ();
            while (i != interno.rend () && *i < 0) {
                contagem += 1;
                i++;
            }
        }
        return contagem;
    }
};

