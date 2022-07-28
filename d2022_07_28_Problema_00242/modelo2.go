func isAnagram(s string, t string) bool {
    
    if len (s) != len (t) {
        return false
    }
    
    contador := make (map [byte] int)
    var existe bool // Auxiliar dentro no laço
    
    for i := 0; i < len (s); i++ { // Tanto faz, s ou t
        
        if _, existe = contador [s [i]]; existe {
            contador [s [i]]++
        } else {
            contador [s [i]] = 1
        }
        
        if _, existe = contador [t [i]]; existe {
            contador [t [i]]--
        } else {
            contador [t [i]] = -1 // Já começa negativo
        }
    }
    
    for _, v := range contador { // Tanto faz, s ou t
        if v != 0 { // Se nao houver equilíbrio, não é anagrama
            return false
        }
    }
    
    return true // Se chegou até aqui, é anagrama
}

