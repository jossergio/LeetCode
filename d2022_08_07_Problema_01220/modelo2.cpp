const int modulo = 1000000007;

class Solution {
public:
    int countVowelPermutation(int n) {
        
        map<char, long int> acumulados;
        int tamanhos = 1;
        
        acumulados ['a'] = 1;
        acumulados ['e'] = 1;
        acumulados ['i'] = 1;
        acumulados ['o'] = 1;
        acumulados ['u'] = 1;
        
        while (tamanhos < n) {
            
            map<char, long int> tmp;
            
            tmp ['a'] = (acumulados ['e'] + acumulados ['u'] + acumulados ['i']) % modulo;
            tmp ['e'] = (acumulados ['a'] + acumulados ['i']) % modulo;
            tmp ['i'] = (acumulados ['e'] + acumulados ['o']) % modulo;
            tmp ['o'] = acumulados ['i'] % modulo;
            tmp ['u'] = (acumulados ['i'] + acumulados ['o']) % modulo;
            
            acumulados.swap (tmp);
            
            tamanhos++;
        } // while tamanhos
        
        return (
            acumulados ['a'] +
            acumulados ['e'] +
            acumulados ['i'] +
            acumulados ['o'] +
            acumulados ['u']) % modulo;
}
};

