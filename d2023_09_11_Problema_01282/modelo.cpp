class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mapa;
        for (int i = 0; i < groupSizes.size (); i += 1)
            mapa [groupSizes [i]].push_back (i);
        vector<vector<int>> resposta;
        for (auto [i, v]: mapa) {
            int base = v.size ();
            while (base > 0) {
                resposta.push_back (vector (v.begin () + base - i, v.begin () + base));
                base -= i;
            }
        }
        return resposta;
    }
};

