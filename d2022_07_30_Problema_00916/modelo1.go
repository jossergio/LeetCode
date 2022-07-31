func maximo (a, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}

func conferir (palavra, padrao [26] int) bool {
    
    for i := 0; i < 26; i++ {
        if padrao [i] > palavra [i] {
            return false
        }
    }
    
    return true
}

func contarLetras (base string) (retorno [26] int) {
    
    for _, c := range base {
        retorno [c - 'a']++
    }
    
    return retorno
}

func wordSubsets(words1 []string, words2 []string) []string {
    
    var resposta [] string
    var maximos [26] int // 0s
    
    for _, padrao := range words2 {
        
        internos := contarLetras (padrao)
        
        for i := 0; i < 26; i++ {
            maximos [i] = maximo (maximos [i], internos [i])
        }
    }
    
    for _, palavra := range words1 {
        
        if conferir (contarLetras (palavra), maximos) {
            resposta = append (resposta, palavra)
        }
    }
    
    return resposta
}

