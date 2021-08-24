package main

import (
	"fmt"
	"strings"
	"strconv"
)

func isAlgarismo (c byte) bool {
	return strings.IndexByte ("0123456789", c) != -1
}

func pegaSinal (s string, p *int) int {
	retorno := 1 // Positivo
	for s [*p] == '+' || s [*p] == '-' {
		if s [*p] == '-' {
			retorno *= -1
		} // if
		*p += 1
	} // for ...
	return retorno
}

func pegaValor (s string, p *int) int {
	modulo := pegaSinal (s, p)
	numero := ""
	for *p < len (s) {
		if isAlgarismo (s [*p]) {
			numero = numero + string (s [*p])
			*p += 1
		} else { // if isAlgarismo...
			break
		} // else if isAlgarismo
	} // for...
	valor, _ := strconv.Atoi (numero)
	return modulo * valor
}

func pegaNImaginario (s string) (int, int) {
	var real, imaginaria int
	var p int = 0
	real = pegaValor (s, &p)
	if s [p] == 'i' { // Não tem parte real e o valor é a imaginária
		imaginaria = real
		real = 0
	} else { // if s p == 'i'
		if p < len (s) {
			imaginaria = pegaValor (s, &p)
		} else { // if p < len s
			imaginaria = 0 // Repetitivo?
		} // else p < len s
	} // else if s p == 'i'
	return real, imaginaria
}

func complexNumberMultiply(num1 string, num2 string) string {
	r1, i1 := pegaNImaginario (num1)
	r2, i2 := pegaNImaginario (num2)
	parteReal := (r1 * r2) - (i1 * i2)
	parteImaginaria := (r1 * i2) + (i1 * r2)
	
	return strconv.Itoa (parteReal) + "+" + strconv.Itoa (parteImaginaria) + "i"
}

func main() {
	var n1 string = "1+-1i"
	var n2 string = "1+-1i"
	fmt.Println (pegaNImaginario (n1))
	fmt.Println (pegaNImaginario (n2))
	fmt.Println ("Multiplicação: ", complexNumberMultiply (n1, n2))
}

