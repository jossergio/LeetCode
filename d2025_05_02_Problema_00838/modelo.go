func pushDominoes(dominoes string) string {
    
    tamanho := len (dominoes)
    tensoes := make ([] int, tamanho)
    
    maior := func (a, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    letra := func (i int) (c rune) {
        switch {
            case i > 0: c = 'R'
            case i < 0: c = 'L'
            case i == 0: c = '.'
        }
        
        return // c
    }
    
    // Mede os direitos
    f := 0
    for i := 0; i < tamanho; i++ {
        switch dominoes [i] {
            case 'R': f = tamanho
            case 'L': f = 0
            default: f = maior (0, f - 1)
        }
        tensoes [i] = f
    }
    
    // Mede os esquerdos
    f = 0
    for i := tamanho - 1; i >= 0; i-- {
        switch dominoes [i] {
            case 'L': f = tamanho
            case 'R': f = 0
            default: f = maior (0, f - 1)
        }
        tensoes [i] -= f
    }
    
    resposta := make ([] rune, tamanho)
    
    for i := range tensoes {
        resposta [i] = letra (tensoes [i])
    }
    
    return string (resposta)
}
