const int modulo = 1000000007;

class Solution {
public:
    int countVowelPermutation(int n) {
        
        long int a = 1, e = 1, i = 1, o = 1, u = 1;
        int tamanhos = 1;
        long int ta, te, ti, to, tu; // Só as definições
        
        while (tamanhos < n) {
            
            ta = (e + u + i) % modulo;
            te = (a + i) % modulo;
            ti = (e + o) % modulo;
            to = i % modulo;
            tu = (i + o) % modulo;
            
            a = ta;
            e = te;
            i = ti;
            o = to;
            u = tu;
            
            tamanhos++;
        } // while tamanhos
        
        return (a + e + i + o + u) % modulo;
    }
};

