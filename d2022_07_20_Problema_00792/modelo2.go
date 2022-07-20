func ehSubsequencia (s string, sub string) bool {
    
    var i, j int // = 0
    
    for i < len (s) && j < len (sub) {
        if s [i] == sub [j] {
            j++
        }
        i++
    }
    
    return j == len (sub)
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

