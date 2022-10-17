class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, bool> mapa;
        int total = 0; // Irá contar o total de caracteres únicos
        for (char c: sentence)
            if (!mapa [c]) {
                mapa [c] = true;
                total += 1;
            }
        return total == 26; // Letras no alfabeto inglês
    }
};

