package main

import (
	"fmt"
	"strings"
)

func maxNumberOfBalloons(text string) int {
	letras := make (map [rune] int)
	letras ['b'] = strings.Count (text, "b")
	letras ['a'] = strings.Count (text, "a")
	letras ['l'] = strings.Count (text, "l") / 2 // Sim
	letras ['o'] = strings.Count (text, "o") / 2 // Idem
	letras ['n'] = strings.Count (text, "n")
	maximo := 2000 // Valor inferido para máximo (sei que é menor que isso)
	for _, valor := range letras {
		if valor < maximo {
			maximo = valor
		} // if valor < maximo
	} // for indice, valor range letras
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

