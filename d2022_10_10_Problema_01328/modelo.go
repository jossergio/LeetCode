func breakPalindrome(palindrome string) string {
    ordem := func (c byte) byte {
        return c - 97
    }
    caractere := func (b byte) byte {
        return b + 97
    }
    limite := len (palindrome) / 2
    trocou := false
    retorno := ""
    for i := 0; i < len (palindrome); i++ {
        if i < limite {
            if ordem (palindrome [i]) > ordem ('a') {
                retorno += string (caractere (ordem ('a')))
                trocou = true
            }
        } else {
            if !(len (palindrome) % 2 == 1 && i == limite) {
                if ordem (palindrome [i]) > ordem ('a') {
                    retorno += string (caractere (ordem ('a')))
                    trocou = true
                } else {
                    if i == len (palindrome) - 1 { // Última chhance de substituição
                        if ordem (palindrome [i]) > ordem ('a') {
                            retorno += string (caractere (ordem ('a')))
                        } else {
                            retorno += string (caractere (ordem (palindrome [i]) + 1))
                        }
                        trocou = true // Para ambos os casos
                    }
                }
            }
        }
        if trocou {
            retorno += palindrome [i + 1:]
            break
        }
        retorno += string (palindrome [i])
    }
    if trocou {
        return retorno
    }
    // else
    return ""
}

