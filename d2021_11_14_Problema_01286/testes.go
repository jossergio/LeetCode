/*
Desafio LeetCode 14/11/2021.
Problema 1286.
Iterador (Iterator) de combinações.
*/

package main

import (
	"fmt"
)

/*
====
Definição básica do tipo
===
*/

type CombinationIterator struct {
	Combinacoes [] string
}

/*
===
Função auxiliar ao Constructor
===
*/

func montarCombinacoes (combs *[] string, comb string, caracteres string, inicio int, nivel int) {
	if nivel == 0 {
		*combs = append (*combs, comb)
	} else { // if nivel == 0
		for i := inicio; i < len (caracteres); i++ {
			montarCombinacoes (combs, comb + string (caracteres [i]), caracteres, i + 1, nivel - 1)
		} // for i
	} // else if nivel == 0
} // montarCombinacoes

/*
===
Funções da estrutura do objeto
===
*/

func Constructor(characters string, combinationLength int) CombinationIterator {
	var combs [] string
	montarCombinacoes (&combs, "", characters, 0, combinationLength)
	return CombinationIterator {combs}
}


func (this *CombinationIterator) Next() string {
	var retorno string
	if this.HasNext () {
		retorno = this.Combinacoes [0]
		this.Combinacoes = this.Combinacoes [1:]
	}
	return retorno
}


func (this *CombinationIterator) HasNext() bool {
	return (len (this.Combinacoes) > 0)
}

/*
===
Fim das funções da estrutura do objeto
===
*/

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */

func main() {
	teste := Constructor ("abc", 2)
	for teste.HasNext () {
		fmt.Println (teste.Next ())
	}
}

