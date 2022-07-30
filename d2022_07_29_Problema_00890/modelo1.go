func formaPadrao (palavra string, padrao string) bool {
    
    comb1 := make (map [rune] rune)
    comb2 := make (map [rune] rune)
    
    for i, c1 := range padrao {
        
        c2 := rune (palavra [i])
        
        if c, existe := comb1 [c1]; existe {
            // Também existe no outro
            if ! (c == c2 && c1 == comb2 [c2]) {
                return false
            }
        } else {
            if _, existe = comb2 [c2]; ! existe {
                comb1 [c1] = c2
                comb2 [c2] = c1
            } else {
                return false
            }
        }
    }
    
    return true
}

func findAndReplacePattern(words []string, pattern string) []string {
    
    var resp [] string
    
    for _, palavra := range words {
        if formaPadrao (palavra, pattern) {
            resp = append (resp, palavra)
        }
    }
    
    return resp
}

