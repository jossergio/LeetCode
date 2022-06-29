const int vazio = -1; // Para ter um parâmetro para valores ainda nulos na resposta

bool ordem (vector<int> a, vector<int> b) {
    if (a [0] == b [0] && (a [1] <= b [1]))
        return true;
    // else
    if (a [0] < b [0])
        return true;
    // else
    return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>> resposta (people.size (), {vazio, vazio});
        
        sort (people.begin (), people.end (), ordem);
        
        for (int i = 0; i < people.size (); i++) {
            int indice = people [i][1];
            int posicao = 0;
            while (indice > 0 || resposta [posicao][0] != vazio) {
                if (resposta [posicao][0] == vazio || resposta [posicao][0] >= people [i][0])
                    indice--;
                posicao++;
            }
            resposta [posicao][0] = people [i][0];
            resposta [posicao][1] = people [i][1];
        }
        
        return resposta;
    }
};

