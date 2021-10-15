package main

import (
	"fmt"
)

var quadrados [] int
var valor int
var gerado bool = false

func qtdQuadrados (item int, nivel int, acumulado int) int {
	nivel++ // Vem por valor
	var retorno int = 0
	for quadrados [item] <= valor {
		acumulado += quadrados [item]
		if acumulado == valor {
			return nivel
		} else { // if acumulado == n
			if acumulado < valor {
				tmp := qtdQuadrados (item, nivel, acumulado)
				if (tmp != 0) && (retorno == 0 || tmp < retorno) {
					retorno = tmp
				} // if (tmp != 0) && (retorno == 0 || tmp < retorno)
			} // if acumulado < n
			acumulado -= quadrados [item]
			item++
		} // else if acumulado == n
	} // for inicio > 0
	return retorno
} // qtdQuadrados

func gerarQuadrados () {
	var potencia, base int = 1, 1 // Primeiro quadrado; primeira base
	for potencia <= 10000 { // Esse é o valor limite, pela definição do problema
		quadrados = append (quadrados, potencia)
		base++
		potencia = base * base
	} // for potencia <= 10000
} // gerarQuadrados

func numSquares(n int) int {
	if !gerado {
		gerarQuadrados ()
		gerado = true
	} // if !gerado
	valor = n // Variável global
	return qtdQuadrados (0, 0, 0)
}

func mostrar (numero int) {
	fmt.Println ("Para ", numero, ": ", numSquares (numero))
} // mostrar

func main() {
	mostrar (12)
	mostrar (9)
	mostrar (21)
	mostrar (100)
	mostrar (99)
	mostrar (50)
	mostrar (49)
	mostrar (48)
	mostrar (322)
	// fmt.Println (quadrados)
}

