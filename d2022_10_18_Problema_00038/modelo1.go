func transformar (s string) (retorno string) {
    retorno = "" // string vazia
    anterior := s [0] // Sempre haverá um
    var contar int = 1 // Já há o primeiro
    for i := 1; i < len (s); i++ { // Inicia pelo segundo
        atual := s [i]
        if atual == anterior {
            contar += 1
        } else {
            retorno += strconv.Itoa (contar)
            retorno += string (anterior)
            anterior = atual
            contar = 1 // Reinicia
        }
    } // for
    retorno += strconv.Itoa (contar)
    retorno += string (anterior)
    return // retorno
}

func countAndSay(n int) string {
    if n == 1 {
        return "1"
    } // else
    return transformar (countAndSay (n - 1))
}

