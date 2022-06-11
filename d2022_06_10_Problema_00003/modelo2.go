func lengthOfLongestSubstring(s string) int {
    
    pLetras := make (map [rune] int)
  
    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    var resp, seq int // = 0
    
    for i, letra := range s {
        
        if p, existe := pLetras [letra]; existe {
            
            resp = maior (resp, i - seq)
            
            if ! (seq > p) {
                seq = p + 1
            }
        }
        
        pLetras [letra] = i
    }
    
    return maior (resp, len (s) - seq)
}

