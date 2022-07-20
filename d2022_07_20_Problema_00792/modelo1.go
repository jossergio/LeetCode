func ehSubsequencia (s string, sub string) bool {
    
    var i, j int // = 0
    
    for i < len (sub) {
        
        for j < len (s) && sub [i] != s [j] {
            j++
        }
        
        if ! (j < len (s)) { // Saiu e não encontrou igual
            return false
        }
        
        i++
        j++ // Tem que somar os dois
    }
    
    return true // Se chegou ao fim da substring, então, é substring
}

func numMatchingSubseq(s string, words []string) int {
    
    var resposta int // = 0
    
    for _, palavra := range words {
        if ehSubsequencia (s, palavra) {
            resposta++
        }
    }
    
    return resposta
}

