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
	var retorno byte = s [*p]
	*p++
	return retorno
} // pegarDigito

func checarDigito (s string, p int) byte {
	return s [p]
}

func pegarValor (s string, p *int) int {
	var digito byte = checarDigito (s, *p)
	var valor string
	for digito >= '0' && digito <= '9' {
		valor += string (pegarDigito (s, p))
		digito = checarDigito (s, *p)
	} // for digito...
	return inteiro (valor)
}

func resolverSobra (operandos *[] int, operadores *[] byte) {
	var tmpOperandos [] int = *operandos
	var tmpOperadores [] byte = * operadores
	var operador byte = pegarPilhaOperadores (&tmpOperadores)
	for operador != '(' {
		operando1 := pegarPilhaOperandos (&tmpOperandos)
		operando2 := pegarPilhaOperandos (&tmpOperandos)
		var fator int = 1
		if operador == '-' {
			fator = -1
		}
		adicionarPilhaOperandos (&tmpOperandos, operando2 + (fator * operando1))
		operador = pegarPilhaOperadores (&tmpOperadores)
	} // for operadores ... != '('
	*operandos = tmpOperandos
	*operadores = tmpOperadores
} // resolver

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

func verificarTopoOperadores (ops [] byte) byte {
	return ops [len (ops) - 1]
} // verificarTopoOperadores

func expressao (s string, posicao *int) int {
	var operadores [] byte
	var operandos [] int
	var p int = *posicao
	var digito byte = pegarDigito (s, &p)  // Tem que retornar '('; nem vou testar
	adicionarPilhaOperadores (&operadores, digito)
	digito = checarDigito (s, p)
	if digito == '-' {
		digito = pegarDigito (s, &p) // Retira o '-'
		digito = checarDigito (s, p) // Verifica o próximo dígito
		for digito == ' ' {
			digito = pegarDigito (s, &p)
			digito = checarDigito (s, p)
		} 
		switch {
			case digito == '(': adicionarPilhaOperandos (&operandos, -1 * expressao (s, &p)) // Será outra expressão
			case digito >= 0 && digito <= '9':
				adicionarPilhaOperandos (&operandos, -1 * pegarValor (s, &p))
		} // switch
	} // if digito == '-'
	for p < len (s) {
		digito = checarDigito (s, p)
		switch {
			case digito == ' ': digito = pegarDigito (s, &p) // Só para retirar
			case digito == '(': adicionarPilhaOperandos (&operandos, expressao (s, &p)) // Será outra expressão
			case digito == '+' || digito == '-':
				digito = pegarDigito (s, &p)
				if verificarTopoOperadores (operadores) != '(' {
					resolver (&operandos, &operadores)
				} // if verificarTopoOperadores
				adicionarPilhaOperadores (&operadores, digito)
			case digito >= '0' && digito <= '9':
				adicionarPilhaOperandos (&operandos, pegarValor (s, &p))
			case digito == ')':
				digito = pegarDigito (s, &p) // Retira o ')'
				resolverSobra (&operandos, &operadores)
				*posicao = p
				return operandos [0]
		} // switch
	} // for posicao < len s
	return 0
} // expressao

func calculate(s string) int {
// Esse algoritmo pressupõe que não há erro de montagem de s
	var posicao int = 0
	return expressao ("(" + s + ")", &posicao)
} // calculates

func trabalharModelos (s string) {
	fmt.Println("Resolvendo [", s, "]: ", calculate (s))
} // trabalharModelos

func main() {
	trabalharModelos ("1 + 1")
	trabalharModelos ("1 + 1 + 1")
	trabalharModelos ("1+1-1")
	trabalharModelos ("-1 - 1")
	trabalharModelos ("(1 + 1 - 2)")
	trabalharModelos ("1 - (2 + 2)")
	trabalharModelos ("(10) + (1)")
	trabalharModelos ("(1) - (1)")
	trabalharModelos ("-(3 + 1)")
}

