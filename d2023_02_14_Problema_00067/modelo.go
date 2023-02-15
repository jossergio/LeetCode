func igualar (s1 string, s2 string) (string, string) {
    var dif int = len (s1) - len (s2)
    switch {
        case dif > 0:
            for dif > 0 {
                s2 = "0" + s2
                dif--
            }
        case dif < 0:
            for dif < 0 {
                s1 = "0" + s1
                dif++
            }
    } // switch
    return s1, s2
} // igualar

func somar (v1 rune, v2 rune, vu rune) (resposta rune, vaiUm rune) {
    switch {
        case v1 == '0' && v2 == '0':
            if vu == '0' {
                resposta = '0'
            } else {
                resposta = '1'
            }
            vaiUm = '0'
        case v1 == '1' && v2 == '1':
            if vu == '0' {
                resposta = '0'
            } else {
                resposta = '1'
            }
            vaiUm = '1'
        default: // Só sobram os diferentes
            if vu == '0' {
                resposta = '1'
                vaiUm = '0'
            } else {
                resposta = '0'
                vaiUm = '1'
            }
    } // switch
    return // resposta, vaiUm
} // somar

func addBinary(a string, b string) string {
    a, b = igualar (a, b)
    var vaiUm rune = '0'
    var resposta string = ""
    var auxiliar rune
    for i := len (a) - 1; i >= 0; i-- { // Tanto faz, a ou b
        auxiliar, vaiUm = somar (rune (a [i]), rune (b [i]), vaiUm)
        resposta = string (auxiliar) + resposta
    } // for
    if vaiUm == '1' {
        resposta = "1" + resposta
    }
    return resposta
}

