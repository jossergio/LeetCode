class Solution {
public:
    int countVowelPermutation(int n) {
        
        queue<char> resp;
        int tamanhos = 1;
        
        resp.push ('a');
        resp.push ('e');
        resp.push ('i');
        resp.push ('o');
        resp.push ('u');
        
        while (tamanhos < n) {
            
            int cont = resp.size ();
            
            while (cont >= 1) {
                char tmp = resp.front ();
                resp.pop ();
                switch (tmp) {
                        case 'a':
                        resp.push ('e');
                        break;
                        case 'e':
                        resp.push ('a');
                        resp.push ('i');
                        break;
                        case 'i':
                        resp.push ('a');
                        resp.push ('e');
                        resp.push ('o');
                        resp.push ('u');
                        break;
                        case 'o':
                        resp.push ('i');
                        resp.push ('u');
                        break;
                        case 'u':
                        resp.push ('a');
                        break;
                        // Não precisa de default     
                } // switch
                
                cont--;
            } // while cont
            
            tamanhos++;
        } // while tamanhos
        
        return (resp.size () % 1000000007);
    }
};

