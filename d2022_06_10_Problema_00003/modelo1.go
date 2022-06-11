func lengthOfLongestSubstring(s string) int {
    
    letras := make (map [rune] bool)

    zerar := func () {
        // Também inicializa
        for c := 'a'; c <= 'z'; c++ {
            letras [c] = false
        }
    }
    
    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    var resp int // = 0
    
    for i := 0; i < len (s); i++ {
        
        zerar ()
        
        var tmp int // = 0
        
        for _, letra := range s [i:] {
            if existe := letras [letra]; existe {
                break // interno
            } else {
                letras [letra] = true
                tmp++
            }
        }
        
        resp = maior (resp, tmp)
    }
    
    return resp
}

