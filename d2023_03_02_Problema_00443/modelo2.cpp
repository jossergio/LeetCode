class Solution {
public:
    int compress(vector<char>& chars) {
        int tamanhoFinal = 0;
        int i = 0; // Será o índice; notar que haverá incremento em laço interno
        while (i < chars.size ()) {
            int tamanhoGrupo = 1;
            while (i + tamanhoGrupo < chars.size () && chars [i + tamanhoGrupo] == chars [i])
                tamanhoGrupo += 1;
            chars [tamanhoFinal++] = chars [i]; // Notar que há duas ações, com o uso de incremento dessa forma
            if (tamanhoGrupo > 1)
                for (char c: to_string (tamanhoGrupo))
                    chars [tamanhoFinal++] = c; // Idem nas duas ações; notar que sobrescreve, somente, a parte do grupo
            i += tamanhoGrupo;
        }
        return tamanhoFinal;
    }
};

