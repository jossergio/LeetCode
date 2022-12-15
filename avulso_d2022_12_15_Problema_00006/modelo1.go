func convert(s string, numRows int) string {
    if numRows == 1 { // Pode provocar problema, no modelo que fiz
        return s // E já adianta, pois essa é a resposta
    }
    linhas := make ([] string, numRows)
    i := 0
    ii := 1 // Será o incremento, alternando
    for _, c := range s {
        linhas [i] += string (c)
        i += ii
        if i < 0 {
            ii = 1 // Volta a ser positivo
            i = 1 // E já segue para a segunda
        }
        if i >= numRows {
            ii = -1 // Passa para negativo
            i = numRows - 2 // Lembrar que é 0-begin
        }
    }
    var resposta string
    for _, linha := range linhas {
        resposta += linha
    }
    return resposta
}

