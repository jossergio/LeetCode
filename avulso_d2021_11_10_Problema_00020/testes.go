package main

import (
	"fmt"
)

/*
Desafio LeetCode 20, feito em 10/11/2021.
Parêntesis válidos.
Envolvia chaves e colchetes, também.
O abrir e fechar tinha que ser consistente, não quebrando duplas.
*/

func teste (pilha [] rune, c rune) bool {
	if len (pilha) > 0 {
		switch c {
			case ')':
				if pilha [len (pilha) - 1] == '(' {
					return true
				} // if pilha '('
			case ']':
				if pilha [len (pilha) - 1] == '[' {
					return true
				} // if pilha '['
			case '}':
				if pilha [len (pilha) - 1] == '{' {
					return true
				} // if pilha '{'
		} // switch c
	} // if len pilha > 0
	return false
}

func isValid(s string) bool {
	var pilha [] rune
	for _, c := range s {
		switch c {
			case '(', '[', '{': pilha = append (pilha, c)
			case ')', ']', '}':
				if teste (pilha, c) {
					pilha = pilha [0:len (pilha) - 1]
				} else { // if teste pilha c
					return false
				} // else if teste pilha c
		} // switch c
	} // for _, c
	if len (pilha) > 0 { // Não pode sobrar
		return false
	} // if len pilha > 0
	return true
}

func main() {
	fmt.Println(isValid ("()"))
	fmt.Println(isValid ("(]"))
	fmt.Println(isValid ("({})"))
	fmt.Println(isValid ("(){}"))
	fmt.Println(isValid ("([)]"))
}

