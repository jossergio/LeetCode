func max (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
} // max

func naoCompartilha (a string, b string) int {
    // len (a) sempre será o maior (ou igual)
    
    teste := make (map [byte] byte)
    
    for i := 0; i < len (a); i++ {
        
        if v, existe := teste [a [i]]; existe {
            if v == 2 { // Existe na 2a string
                return 0
            }
        } else {
            teste [a [i]] = 1 // Passa a existir na 1a string
        }
        
        if ! (i < len (b)) {
            continue
        }
        
        if v, existe := teste [b [i]]; existe {
            if v == 1 { // Existe na 1a string
                return 0
            }
        } else {
            teste [b [i]] = 2 // Passa a existir na segunda
        }
    }
    
    return len (a) * len (b)
} // naoCompartilha

func testar (a string, b string) int {
    // Retorna len (a) x len (b) ou 0
    // Só faz teste de tamanhos
    
    if len (a) > len (b) {
        return naoCompartilha (a, b)
    }
    // else
    return naoCompartilha (b, a)
} // testar


func maxProduct(words []string) int {
    
    var resp int // = 0
    
    for i := 0; i < len (words) - 2; i++ {
        for j := i + 1; j < len (words); j++ {
            resp = max (resp, testar (words [i], words [j]))
        }
    }
    
    return resp
}

