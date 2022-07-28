func isAnagram(s string, t string) bool {
    
    if len (s) != len (t) {
        return false
    }
    
    sContador := make (map [byte] int)
    tContador := make (map [byte] int)
    var existe bool // Auxiliar no laço abaixo
    
    for i := 0; i < len (s); i++ { // Tanto faz, s ou t
        
        if _, existe = sContador [s [i]]; existe {
            sContador [s [i]]++
        } else {
            sContador [s [i]] = 1
        }
        
        if _, existe = tContador [t [i]]; existe {
            tContador [t [i]]++
        } else {
            tContador [t [i]] = 1
        }
    }
    
    for c, vs := range sContador { // Tanto faz, s ou t
        if vt, existe := tContador [c]; ! (existe && (vt == vs)) {
            return false
        }
    }
    
    return true
}

