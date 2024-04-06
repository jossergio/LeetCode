func minRemoveToMakeValid(s string) string {
    
    var tmp string // = ""
    var contador int // = 0
    
    for _, c := range (s) {
        switch c {
            case '(':
                contador++
                tmp += string (c)
            case ')':
                contador--
                if contador >= 0 {
                    tmp += string (c)
                } else {
                    contador = 0 // Só deixa ir até -1
                }
            default:
                tmp += string (c)
        } // switch
    } // for
    
    var resposta string // == ""
    
    if contador > 0 {
        for i := len (tmp) - 1; i >= 0; i-- {
            if tmp [i] == '(' {
                if contador > 0 { // Só pode chegar a zero
                    contador--
                    if contador == 0 { // Chegou a zero
                        resposta = tmp [:i] + resposta
                        break
                    } else {
                        continue
                    }
                }
            }
            resposta = string (tmp [i]) + resposta
        }
    } else { // Só pode ser o zero
        resposta = tmp
    }
    
    return resposta
}

