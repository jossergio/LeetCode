func concatenatedBinary(n int) int {
    
    const MODULO int = 1000000007
    var acumulado int // = 0
    
    for i := 1; i <= n; i++ {
        
        deslocamento := i // Desloca com base no bit 1 mais significativo do valor que vai entrar, para dar espao
        
        for deslocamento > 0 {
            acumulado <<= 1 // Desloca para a esquerda
            deslocamento >>= 1 // Desloca para a direita
        }
        
        acumulado += i
        acumulado %= MODULO
    }
    
    return acumulado
}

