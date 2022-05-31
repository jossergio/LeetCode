func maior (a int, b int) int {
    // Para não utilizar o de math
    if a > b {
        return a
    }
    // else
    return b
}

func maxProduct(words []string) int {
    bits := make ([] uint32, len (words))
    
    for i := range words { // Pega, somente, os índices
        for _, c := range words [i] { // Pega caractere a caractere
            bits [i] |= (1 << (c - 'a'))
        }
    }
    
    var resp int // = 0
    
    for i := 0; i < (len (bits) - 1); i++ {
        for j := i + 1; j < len (bits); j++ {
            if (bits [i] & bits [j]) == 0 {
                resp = maior (resp, len (words [i]) * len (words [j]))
            }
        }
    }
    
    return resp
}

