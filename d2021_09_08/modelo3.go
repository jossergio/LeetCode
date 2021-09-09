func adicionar (letra byte, valor int) (byte) {
    var tmp byte = letra - 97 // Letra 'a'
    tmp = byte ((int (tmp) + valor) % 26)
    return tmp + 97
} // adicionar

func shiftingLetters(s string, shifts []int) string {
    retorno := make ([] byte, len (s))
    var total int
    for indice := len (s) - 1; indice >= 0; indice-- {
	total += shifts [indice]
        retorno [indice] = adicionar (byte (s [indice]), total)
    } // for indice, letra
    return string (retorno)
}

