func auxPalindromo (s string, i int, j int) bool {
    for i < j {
        if s [i] != s [j] {
            return false
        }
        i++
        j--
    }
    return true
}

func validPalindrome(s string) bool {
    
    var esquerda, direita int = 0, len(s) - 1
    
    for esquerda < direita {
        if s [esquerda] != s [direita] {
            return auxPalindromo (s, esquerda, direita - 1) || auxPalindromo (s, esquerda + 1, direita)
        }
        esquerda++
        direita--
    }
    
    return true
}

