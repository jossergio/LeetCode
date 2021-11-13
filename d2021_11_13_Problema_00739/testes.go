/*
Desafio LeetCode em 13/11/2021.

Problema 00739.

Dias em que a temperatura não aumenta (com acumulador).
*/

package main

import (
	"fmt"
)

func dailyTemperatures(temperatures []int) []int {
	tamanho := len (temperatures) // Será usado várias vezes
	var resultado [] int
	var acumulado int
	for i := 0; i < tamanho - 1; i++ {
		acumulado = 1 // Inicia
		i2 := i + 1 // Preciso do valor ao final
		for i2 < tamanho {
			if temperatures [i] >= temperatures [i2] {
				acumulado++
			} else { // if temperatures >= temperatures [i2]
				break
			} // else if temperatures [i] >= temperatures [i2]
			i2++
		} // for i2
		if ! (i2 < tamanho) {
			acumulado = 0 // Acumulou e não encontrou
		} // if ! i2 < tamanho
		resultado = append (resultado, acumulado)
	} // for i, v
	resultado = append (resultado, 0) // Sempre termina assim; o último não tem comparativos
	return resultado
}

func mostrar2 (valores [] int) {
// Mostra vetores
	for _, v := range valores {
		fmt.Print (v, " ")
	} // for _, v
	fmt.Println ()
} // mostrar 2

func mostrar (valores [] int) {
	fmt.Println ("Temperaturas:")
	mostrar2 (valores)
	fmt.Println ("Resultado:")
	mostrar2 (dailyTemperatures (valores))
} // mostrar

func main() {
	mostrar ([] int {73,74,75,71,69,72,76,73})
	mostrar ([] int {30,40,50,60})
	mostrar ([] int {30,60,90})
	mostrar ([] int {89,62,70,58,47,47,46,76,100,70})
}

