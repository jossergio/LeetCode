func findTheDifference(s string, t string) byte {
    
    letras := make (map [rune] int)
    
    for _, letra := range s {
        if _, existe := letras [letra]; !existe {
            letras [letra] = 1
        } else { // if
            letras [letra]++
        } // else if
    } // for range s
    
    for _, letra := range t {
        if _, existe := letras [letra]; !existe {
            return byte (letra) // Já achou
        } else { // if
            letras [letra]--
        } // else if
    } // for range t
    
    for letra, v := range letras {
        if v == 1 || v == -1 { // Ou sobrou um ou tirou mais que devia, por letra igual foi a que sobrou
            return byte (letra)
        }
    }

    return 0 // Nunca chega aqui; ou não deve chegar
}

