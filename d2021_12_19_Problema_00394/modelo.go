func pegarTrecho (entrada string, posicao *int) (trecho string) {
    if entrada [*posicao] >= 'a' && entrada [*posicao] <= 'z' {
        for *posicao < len (entrada) && entrada [*posicao] >= 'a' && entrada [*posicao] <= 'z' {
            trecho += string (entrada [*posicao])
            *posicao++
        }
    } else { // if entrada *posicao ...
        var numero int
        var tmp string
        for entrada [*posicao] != '[' { // É garantido, pelo problema, que não há falhas de composição de entrada
            numero *= 10
            numero += int (entrada [*posicao] - '0')
            *posicao++
        }
        *posicao++ // Passa o [
        for entrada [*posicao] != ']' { // Idem, garantia
            if entrada [*posicao] >= '0' && entrada [*posicao] <= '9' {
                tmp += pegarTrecho (entrada, posicao)
            } else {
                tmp += string (entrada [*posicao])
                *posicao++
            }
            if entrada [*posicao] >= '0' && entrada [*posicao] <= '9' {
                tmp += pegarTrecho (entrada, posicao)
            }
        }
        *posicao++ // Passa o ]
        for i := 1; i <= numero; i++ {
            trecho += tmp
        }
    } // else if entrada *posicao
    return
} // pegarTrecho

func decodeString(s string) string {
    var resposta string
    var posicao int
    for posicao < len (s) {
        resposta += pegarTrecho (s, &posicao)
    }
    return resposta
}

