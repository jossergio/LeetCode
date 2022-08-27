var inicio bool = true
var valores [] string // Vazio

func paraString (n int) (resposta string) {
    
    digito := func (i int) string {
        return string (rune (i + 48))
    }
    
    for n > 0 {
        resposta = digito (n % 10) + resposta
        n /= 10
    }
    
    return // resposta
}

func iniciar () {
    
    for i := 1; i <= 1000000000; i *= 2 {
        valores = append (valores, paraString (i))
    }
}

func comparar (s1, s2 string) bool {
    
    // Os tamanhos devem ser idênticos; testagem antes da chamada à função
    
    var contagem [26] int // Tudo zero; apesar de maior, maps seria lento
    
    valor := func (b byte) byte {
        return b - 48
    }
    
    for i := 0; i < len (s1); i++ {
        contagem [valor (s1 [i])]++
        contagem [valor (s2 [i])]--
    }
    
    for i := 0; i < 26; i++ {
        if contagem [i] != 0 {
            return false
        }
    }
    
    return true
}

func reorderedPowerOf2(n int) bool {
    
    if inicio {
        iniciar ()
        inicio = false
    }
    
    nStr := paraString (n)
    
    for _, linha := range valores {
        if (len (linha) == len (nStr)) {
            if comparar (linha, nStr) {
                return true
            }
        } else {
            if (len (linha) > len (nStr)) {
                break // Não precisa mais comparar
            }
        }
    }
    
    return false // Se chegou até aqui
}

