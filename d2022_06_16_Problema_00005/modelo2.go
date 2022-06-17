func maiorPalindromoLocal (s string, i int, f int) (inicio int, final int) {
    // Retorna, a partir de uma base central, o maior palíndromo
    // dentro dos limites da string
    
    inicio = i
    final = f
    
    for (inicio >= 0 && final < len (s)) && (s [inicio] == s [final]) {
        inicio--
        final++
    }
    
    if ! ((inicio >= 0 && final < len (s)) && s [inicio] == s [final]) {
        inicio += 1
        final -= 1
    }
    
    return // inicio, final
}

func longestPalindrome(s string) string {
    
    var rInicio, rFinal int // = 0, 0
    
    // Temporárias no laço
    var inicio, final int // = 0, 0
    
    for i := 0; i < len (s); i++ {
        
        inicio, final = maiorPalindromoLocal (s, i, i) // Para palíndromos ímpares
        
        if (final - inicio) > (rFinal - rInicio) {
            rInicio, rFinal = inicio, final
        }
        
        // Segunda passada, para palídromos pares
        inicio, final := maiorPalindromoLocal (s, i, i + 1)
        if (final - inicio) > (rFinal - rInicio) {
            rInicio, rFinal = inicio, final
        }
    }
    
    return s [rInicio:rFinal + 1] // O último não entraria
}

