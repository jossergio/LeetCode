class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, bool> mapa;
        int total = 0; // Irá contar o total de caracteres únicos
        for (char c: sentence)
            if (!mapa [c]) {
                mapa [c] = true;
                if ((++total) == 26) // Letras no alfabeto ingLês; para sair logo
                    return true;
            }
        return false; // Por omissão, se chegou até aqui
    }
};

