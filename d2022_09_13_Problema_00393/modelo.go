func checarBits (padrao, valor, indice int) bool { // Checa bits conforme um padrão
    if indice > 0 {
        if !(((1 << indice) & valor) == 0) { // O bit dessa posição, mais significativa, é zero
            return false
        }
    }
    // else
    return (padrao & valor) == padrao
}

func testar (d [] int, i *int, n int) bool {
    
    var contar int = 0
    
    *i++
    
    for contar < n && *i < len (d) {
        if !checarBits (0b10000000, d [*i], 6) {
            return false // Já retorna daqui
        }
        *i++
        contar++
    }
    
    return contar == n // Último teste
}

func validUtf8(data []int) bool {
    
    var i int // = 0
    
    for i < len (data) {
        
        if checarBits (0b10000000, data [i], 0) { // O bit mais significativo é 1
            switch {
                case checarBits (0b11110000, data [i], 3):
                if !testar (data, &i, 3) {
                    return false
                }
                case checarBits (0b11100000, data [i], 4):
                if !testar (data, &i, 2) {
                    return false
                }
                case checarBits (0b11000000, data [i], 5):
                if !testar (data, &i, 1) {
                    return false
                }
                default:
                    return false // Não encaixa em padrão algum desses
            }
        } else {
            i++
        }
    }
    
    return true // Procura por uma invalidade; se não encontra, é verdadeiro
}

