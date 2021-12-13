func maxPower(s string) int {
    var resposta = 1
    var n = len (s)
    var acumulado = 1
    for i := 1; i < n; i++ {
        if s [i] == s [i - 1] {
            acumulado++
            if acumulado > resposta {
                resposta = acumulado
            } // if acumulado > resposta
        } else { // if s == s [-1]
            acumulado = 1
        } // else if s == s [-1]
    } // for i
    return resposta
}

