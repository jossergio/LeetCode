class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, vector<int>> listagem;
        
        for (int i = 0; i < s.size (); i++)
            listagem [s [i]].push_back (i);
        
        int resposta = s.size () + 1; // Para referência
        
        for (auto item: listagem)
            if (item.second.size () == 1)
                if (item.second [0] < resposta)
                    resposta = item.second [0];
        
        return (resposta > s.size ())? -1: resposta;
    }
};

