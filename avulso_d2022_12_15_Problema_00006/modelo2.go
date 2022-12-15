func convert(s string, numRows int) string {
    if numRows == 1 { // Causa problema com o modelo de algoritmo utilizado
        return s // Além de adiantar, essa é a resposta
    }
    linhas := make ([] string, numRows)
    proximo := 0 // Próximo caractere
    i := 0
    for proximo < len (s) {
        // Parte incremental
        for proximo < len (s) && i < numRows  {
            linhas [i] += string (s [proximo])
            i += 1
            proximo += 1
        }
        i -= 2 // Para voltar uma linha; 0-begin
        // Parte decremental
        for proximo < len (s) && i >= 0 {
            linhas [i] += string (s [proximo])
            i -= 1
            proximo += 1
        }
        i += 2 // Para subir uma linha; 0-begin
    }
    var resposta string
    for _, linha := range linhas {
        resposta += linha
    }
    return resposta
}

