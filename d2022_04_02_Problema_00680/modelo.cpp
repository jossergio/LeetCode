class Solution {
private:
    bool auxPalindromo (string s, int i, int j) {
        while (i < j) {
            if (s [i] != s [j])
                return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        int esquerda = 0;
        int direita = s.size () - 1;
        
        while (esquerda < direita) {
            if(s [esquerda] != s [direita])
                return auxPalindromo (s, esquerda, direita - 1) || auxPalindromo (s, esquerda + 1, direita);
            esquerda++;
            direita--;
        }
        
        return true;
    }
};

