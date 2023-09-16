func minDeletions(s string) int {
    
    letras := make (map [rune] int)
    
    for _, c := range s {
        if _, existe := letras [c]; existe {
            letras [c]++
        } else {
            letras [c] = 1
        }
    }
    
    totais := make (map [int] rune)
    var resp int // = 0
    
    for i, t := range letras {
        tmp := t
        _, existe := totais [tmp]
        for existe && tmp > 0 {
            resp++
            tmp--
            _, existe = totais [tmp]
        }
        if tmp > 0 {
            totais [tmp] = i
        }
    }
    
    return resp
}

