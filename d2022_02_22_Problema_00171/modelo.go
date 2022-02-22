func titleToNumber(columnTitle string) int {
    
    var base int = 1 // Unidade, dezena, centena... (x26)
    var resposta int // = 0
    
    for i := len (columnTitle) - 1; i >=0; i-- {
        resposta += (int (columnTitle [i]) - 64) * base
        base *= 26
    }
    
    return resposta
}

