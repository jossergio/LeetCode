func ehPadrao (padrao, palavra string) bool {
    
    comb := make (map [rune] rune)
    contem := make(map [rune] bool)
    
    for i, p := range padrao {
        
        c := rune (palavra [i])
        
        if _, existe := comb [c]; existe {
            if comb [c] != p {
                return false
            }
        } else {
            comb [c] = p
        }
    }
    
    for _, c := range comb {
        if _, e := contem [c]; ! e {
            contem [c] = true
        } else {
            return false
        }
    }
    
    return true
}


func findAndReplacePattern(words []string, pattern string) []string {
    
    var resposta [] string
    
    for _, palavra := range words {
        if ehPadrao (pattern, palavra) {
            resposta = append (resposta, palavra)
        }
    }
    
    return resposta
}

