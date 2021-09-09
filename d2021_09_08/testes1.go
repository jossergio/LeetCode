package main

import (
	"fmt"
)

func soma (vetor [] int) (retorno int) {
    for _, v := range (vetor) {
        retorno += v
    } // for a
    return
} // soma

func adicionar (letra byte, valor int) (byte) {
    var tmp byte = letra - 97 // Letra 'a'
    tmp = byte ((int (tmp) + valor) % 26)
    return tmp + 97
} // adicionar

func shiftingLetters(s string, shifts []int) string {
    retorno := make ([] byte, len (s))
    total := soma (shifts)
    for indice, letra := range (s) {
        retorno [indice] = adicionar (byte (letra), total)
        total -= shifts [indice]
    } // for indice, letra
    return string (retorno)
}

func main() {
	// s := "abc"
	// shifts := [] int {3, 5, 9}
	
	s := "aaa"
	shifts := [] int {1, 2, 3}
	
	fmt.Println (shiftingLetters (s, shifts))
}

