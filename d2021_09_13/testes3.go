package main

import (
	"fmt"
	"strings"
)

func maxNumberOfBalloons(text string) int {
	var maximo int = 2000
	for _, letra := range "balon" {
		valor := strings.Count (text, string (letra))
		if letra == 'l' || letra == 'o' {
			valor /= 2
		} // if letra...
		if valor == 0 {
			return 0 // Nem precisa mais
		} else { // if valor == 0
			if valor < maximo {
				maximo = valor
			} // if valor < maximo
		} // else if valor == 0
	}
	return maximo
}

func mostrar (s string) {
	fmt.Println ("Mostrando valor para ", s, ": ", maxNumberOfBalloons (s))
} // mostrar

func main() {
	mostrar ("balloon")
	mostrar ("nlaebolko")
	mostrar ("leetcode")
	mostrar ("loonbalxballpoon")
	
}

