func maximo (a, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}

func conferir (palavra, padrao map [rune] int) bool {
    
    for c, v1 := range padrao {
        if v2, existe := palavra [c]; existe {
            if v1 > v2 {
                return false
            }
        } else {
            return false // Idem
        }
    }
    
    return true
}

func contarLetras (base string) (retorno map [rune] int) {
    
    retorno = make (map [rune] int)
    
    for _, c := range base {
        if _, existe := retorno [c]; existe {
            retorno [c]++
        } else {
            retorno [c] = 1
        }
    }
    
    return // retorno
}

func wordSubsets(words1 []string, words2 []string) []string {
    
    var resposta [] string
    
    maximos := make (map [rune] int)
    
    for _, padrao := range words2 {
        
        internos := contarLetras (padrao)
        
        for c, v := range internos {
            if _, existe := maximos [c]; existe {
                maximos [c] = maximo (maximos [c], v)
            } else {
                maximos [c] = v
            }
        }
    }
    
    for _, palavra := range words1 {
        
        if conferir (contarLetras (palavra), maximos) {
            resposta = append (resposta, palavra)
        }
    }
    
    return resposta
}

