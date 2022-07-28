func isAnagram(s string, t string) bool {
    
    if len (s) != len (t) {
        return false
    }
    
    var contador [26] int // zerado
    
    for i := 0; i < len (s); i++ { // Tanto faz, s ou t
        
        contador [s [i] - 'a']++
        contador [t [i] - 'a']--
    }
    
    for _, v := range contador { // Tanto faz, s ou t
        if v != 0 { // Se nao houver equilíbrio, não é anagrama
            return false
        }
    }
    
    return true // Se chegou até aqui, é anagrama
}

