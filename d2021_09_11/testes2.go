package main

import (
	"fmt"
	"math"
)

func inteiro (s string) int {
	var retorno int = 0
	var potencia = 0
	for a := len (s) - 1; a >= 0; a-- {
		retorno += int (s [a] - 48) * int (math.Pow (float64 (10), float64 (potencia)))
		potencia++
	} // for a
	return retorno
} // inteiro

func adicionarPilhaOperadores (ops *[] byte, op byte) {
	var temp [] byte = *ops
	temp = append (temp, op)
	*ops = temp
} // adicionarPilhaOperadores

func pegarPilhaOperadores (ops *[] byte) byte {
	var temp [] byte = *ops
	var retorno byte = temp [len (temp) - 1]
	temp = temp [0:len (temp) - 1]
	*ops = temp
	return retorno
} // retirarPilhaOperadores

func adicionarPilhaOperandos (ops *[] int, op int) {
	var temp [] int = *ops
	temp = append (temp, op)
	*ops = temp
} // adicionarPilhaOperadores

func pegarPilhaOperandos (ops *[] int) int {
	var temp [] int = *ops
	var retorno int = temp [len (temp) - 1]
	temp = temp [0:len (temp) - 1]
	*ops = temp
	return retorno
} // retirarPilhaOperandos

func pegarDigito (s string, p *int) byte {
	var retorno byte
	if *p < len (s) {
		retorno = s [*p]
		*p++
	} else { // if p < len s
		retorno = 0
	} // else if p < len s
	return retorno
} // pegarDigito

func pegarValor (s string, digito byte, p *int) int {
	var d byte = digito
	var valor string = string (digito)
	if (*p < len (s)) {
		d = s [*p]
		for d >= '0' && d <= '9' {
			valor += string (d)
			*p++
			if *p < len (s) {
				d = s [*p]
			} else { // if *p < len s
				d = 0
			} // else if *p < len s
		} // for d...
	} // for d...
	return inteiro (valor)
}

func resolver (operandos *[] int, operadores *[] byte) {
	var tmpOperandos [] int = *operandos
	var tmpOperadores [] byte = *operadores
	var operador = pegarPilhaOperadores (&tmpOperadores)
	var operando1 = pegarPilhaOperandos (&tmpOperandos)
	var operando2 = pegarPilhaOperandos (&tmpOperandos)
	var fator int = 1
	if operador == '-' {
		fator = -1
	} // if operador == '-'
	adicionarPilhaOperandos (&tmpOperandos, operando2 + (fator * operando1))
	*operandos = tmpOperandos
	*operadores = tmpOperadores
} // resolver

func expressao (s string, posicao *int) int {
	var operadores [] byte
	var operandos [] int
	var p int = *posicao
	var digito byte = pegarDigito (s, &p)
	for digito == ' ' {
		digito = pegarDigito (s, &p)
	} // for digito == ' '
	switch {
		case digito == '-':
			digito = pegarDigito (s, &p) // Pega o próximo dígito
			for digito == ' ' {
				digito = pegarDigito (s, &p)
			} // for digito == ' '
			switch {
				case digito == '(':
					adicionarPilhaOperandos (&operandos, -1 * expressao (s, &p)) // Será outra expressão
				case digito >= '0' && digito <= '9':
					adicionarPilhaOperandos (&operandos, -1 * pegarValor (s, digito, &p))
			} // switch
			digito = pegarDigito (s, &p)
		case digito == '(':
			adicionarPilhaOperandos (&operandos, expressao (s, &p)) // Será outra expressão
			digito = pegarDigito (s, &p)
		case digito >= '0' && digito <= '9':
			adicionarPilhaOperandos (&operandos, pegarValor (s, digito, &p))
			digito = pegarDigito (s, &p)
	} // switch
	for digito != 0 {
		switch {
			case digito == ' ': digito = pegarDigito (s, &p) // Ignora e pega o próximo
			case digito == '(':
				adicionarPilhaOperandos (&operandos, expressao (s, &p)) // Será outra expressão
				digito = pegarDigito (s, &p)
			case digito == '+' || digito == '-':
				if len (operadores) > 0 {
					resolver (&operandos, &operadores)
				} // if len operadores > 0
				adicionarPilhaOperadores (&operadores, digito)
				digito = pegarDigito (s, &p)
			case digito >= '0' && digito <= '9':
				adicionarPilhaOperandos (&operandos, pegarValor (s, digito, &p))
				digito = pegarDigito (s, &p)
			case digito == ')': digito = 0 // Sai
		} // switch
	} // digito != 0
	for len (operadores) > 0 {
		resolver (&operandos, &operadores)
	} // for len operadores > 0
	*posicao = p
	return operandos [0]
} // expressao

func calculate(s string) int {
// Esse algoritmo pressupõe que não há erro de montagem de s
	var posicao int = 0
	return expressao (s, &posicao)
} // calculates

func trabalharModelos (s string) {
	fmt.Println("Resolvendo [", s, "]: ", calculate (s))
} // trabalharModelos

func main() {
	trabalharModelos ("- (3 + (4 + 5))")
	trabalharModelos ("1")
	trabalharModelos ("1 + 1")
	trabalharModelos ("1+1+1")
	trabalharModelos ("1+1-1")
	trabalharModelos ("-1 - 1")
	trabalharModelos ("(1 + 1 - 2)")
	trabalharModelos ("1 - (2 + 2)")
	trabalharModelos ("(10) + (1)")
	trabalharModelos ("(1) - (1)")
	trabalharModelos ("-(3 + 1)")
}

