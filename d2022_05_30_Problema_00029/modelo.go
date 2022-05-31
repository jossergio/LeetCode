func valorSinal (i int) (valor int, sinal int) {
    // Evita utilizar o pacote math de GoLang
    // sinal pode ser int. Só guarda o sinal.
    
    sinal = 1 // Pressupõe positivo
    valor = i // Pressupõe ser positivo
    
    if i < 0 {
        
        sinal = -1
        
        if i == math.MinInt32 { // Só para o LeetCode não "frescar" nesse caso extremo
            valor = math.MaxInt32 + 1
        } else {
            valor *= -1 // Torna positivo
        }
    }
    
    return
}

func divide(dividend int, divisor int) int {
    
    if divisor == 1 { // Para adiantar e tirar uma condição do extremo (LeetCode)
        return dividend
    }
    
    valorDividendo, sinalDividendo := valorSinal (dividend)
    valorDivisor, sinalDivisor := valorSinal (divisor)
    
    var resposta int = 0
    
    for valorDividendo >= valorDivisor {
        resposta++
        valorDividendo -= valorDivisor
    }
    
    fmt.Println (resposta)

    resposta = resposta * sinalDivisor * sinalDividendo
    
    switch {
    case resposta > math.MaxInt32: resposta = math.MaxInt32
    case resposta < math.MinInt32: resposta = math.MinInt32
    } // Não precisa de valor padrão etc
    
    return resposta
}

